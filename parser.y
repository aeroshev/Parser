%{
    #define YYDEBUG 0
    #define YYERROR_VERBOSE 0
    #include "Prog.h"

    extern FILE * yyin;
    extern int yylineno;
    extern int yy_flex_debug;

    int yylex(void);
    void yyerror(char *s);
    void COMP_ERROR(const char*);
    Vertex* ERROR(const std::string&, int);

    bool errorFlag = false;


    std::vector<std::vector<uint64_t> > map = { {1, 1, 1, 1, 1, 1, 1},
                                                {1, 0, 0, 0, 1, 0, 1},
                                                {1, 1, 1, 0, 1, 0, 1},
                                                {1, 0, 0, 0, 0, 0, 1},
                                                {1, 1, 1, 0, 1, 1, 1},
                                                {1, 0, 0, 0, 0, 0, 1},
                                                {1, 1, 1, 1, 1, 2, 1} };
    
    
    std::pair<uint64_t, uint64_t> start = std::make_pair(1, 1);
    std::pair<uint64_t, uint64_t> vision = std::make_pair(1, 0);

    MAIN_CLASS machine(start, vision, map);

    void freeNode(Vertex *);

%}

%union
{
    Vertex *nPtr;
    int iValue;
    bool iBool;
    char* iName;  
}


%token <iValue> INTEGER
%token <iName> VARIABLE
%token <iBool> BOOL


%token FINDEXIT
%token TASK DO GET RESULT
%token MXCOMP ELCOMP MXFALSE MXTRUE NOT AND LOGITIZE DIGITIZE SIZE REDUCE EXTENED
%token R_LEFT R_RIGHT MOVE GET_E
%token VAR
%token ENDLINE
%token FOR BOUNDARY STEP SWITCH
%token PRINT
%token PLEASE THANKS


%left '+' '-'
%left '*' '/' AND
%left '(' ')'
%nonassoc UMINUS
%nonassoc '[' ']'

%type <nPtr> function_s function_definition  function_list call_definition binary_operation switch_state expression_list statement_s appeal_state for_loop compound_statement block_item unary_statement definition compare_operation unary_operation robot_operation expression statement statement_list declaration_list


%%
program:
        function_list                           { 
                                                    if (!errorFlag)
                                                    {
                                                        machine.check_main($1); 
                                                    }
                                                    freeNode($1);
                                                    exit(0);    
                                                }
        ;

function_list:
        function_s                              { $$ = $1; }
        | function_list function_s              { $$ = machine.create("ENDLINE", 2, $1, $2); }
        ;

function_s:
        function_definition             { $$ = $1; }
        | ENDLINE                       { $$ = nullptr; }
        ;

statement_list:
        statement                               { $$ = $1; }
        | statement_list statement              { $$ = machine.create("ENDLINE", 2, $1, $2); }
        ;

function_definition:
        TASK VARIABLE VARIABLE ',' '[' declaration_list ']' ENDLINE statement_list RESULT VARIABLE           { $$ = nullptr; machine.putFunc($2, $3, $9, $11); delete $2; delete $3; delete $11; }
        | TASK VARIABLE VARIABLE ENDLINE statement_list RESULT VARIABLE                                      { $$ = nullptr; machine.putFunc($2, $3, $5, $7); delete $2; delete $3; delete $7; }
        | TASK FINDEXIT ENDLINE statement_list RESULT                                                        { $$ = $4; machine.putFunc($4); }
        | TASK VARIABLE VARIABLE error '[' declaration_list ']' ENDLINE statement_list RESULT VARIABLE       { $$ = ERROR("Missed ','", @4.first_line); yyerrok; }
        | TASK VARIABLE error                                                                                { $$ = ERROR("Missed variable", @2.first_line); yyerrok; }
        | TASK error VARIABLE ',' '[' declaration_list ']' ENDLINE statement_list RESULT VARIABLE            { $$ = ERROR("Missed name function", @2.first_line); yyerrok ; delete $3; delete $11; }
        | TASK error VARIABLE ENDLINE statement_list RESULT VARIABLE                                         { $$ = ERROR("Missed name function", @2.first_line); yyerrok ; delete $3; delete $7; }
        | TASK VARIABLE VARIABLE ',' '[' declaration_list ']' ENDLINE statement_list error                   { $$ = ERROR("Function must end RESULT", @1.first_line); yyerrok; }
        | TASK VARIABLE VARIABLE ENDLINE statement_list error                                                { $$ = ERROR("Function must end RESULT", @1.first_line); yyerrok; }
        | TASK FINDEXIT ENDLINE statement_list error                                                              { $$ = ERROR("Function must end RESULT", @1.first_line); yyerrok; }
        | TASK VARIABLE VARIABLE ',' '[' declaration_list ']' ENDLINE statement_list RESULT error            { $$ = ERROR("Not provided variable for RESULT", @10.first_line); yyerrok; delete $2; delete $3; }
        | TASK VARIABLE VARIABLE ENDLINE statement_list RESULT error                                         { $$ = ERROR("Not provided variable for RESULT", @6.first_line); yyerrok; delete $2; delete $3; }
        | TASK error                                                                                         { $$ = ERROR("Somthening wrong in body function", @2.first_line); yyerrok; }
        ;

call_definition:
        DO VARIABLE VARIABLE ',' '[' declaration_list ']'               { $$ = machine.funcall("DO", $2, $3, machine.args); delete $2; delete $3; }
        | DO VARIABLE VARIABLE                                          { $$ = machine.funcall("DO", $2, $3); delete $2; delete $3; }
        | DO error VARIABLE                                             { $$ = ERROR("Missed name function", @2.first_line); yyerrok; delete $3; }
        | DO error VARIABLE ',' '[' declaration_list ']'                { $$ = ERROR("Missed name function", @2.first_line); yyerrok; delete $3; }
        | DO VARIABLE error                                             { $$ = ERROR("Missed argument function", @3.first_line); yyerrok; delete $2; }
        | DO VARIABLE VARIABLE '[' declaration_list ']'                 { $$ = ERROR("Missed ','", @3.first_line); yyerrok; delete $2; delete $3; }
        | DO error                                                      { $$ = ERROR("Not atribute for call function", @1.first_line); yyerrok; }                     
        ;

declaration_list:
        VARIABLE                                { $$ = nullptr; machine.args.push_back($1); delete $1; }
        | declaration_list ',' VARIABLE         { $$ = nullptr; machine.args.push_back($3); delete $3; }
        ;

expression_list:
        expression                                  { $$ = nullptr; machine.exprl.push_back($1); }
        | expression_list ',' expression            { $$ = nullptr; machine.exprl.push_back($3); }
        ;

expression:
    BOOL                                        { $$ = machine.constant($1, "BOOL"); }
    | INTEGER                                   { $$ = machine.constant($1, "INT"); }
    | VARIABLE                                  { $$ = machine.id($1); delete $1; }
    | binary_operation                          { $$ = $1; }
    | robot_operation                           { $$ = $1; }
    | unary_operation                           { $$ = $1; }
    | VARIABLE '[' expression_list ']'          { $$ = machine.appeal("APPEAL", $1); delete $1; }
    | VARIABLE '[' error ']'                    { $$ = ERROR("Missed enumeration", @3.first_line); yyerrok; delete $1; }
    | VARIABLE '[' expression_list              { $$ = ERROR("Missed ']'", @3.first_line); yyerrok; delete $1; }
    | '(' expression ')'                        { $$ = $2; }
    | '(' error ')'                             { $$ = ERROR("Error in ()", @1.first_line); yyerrok; }
    ;

binary_operation:
    expression '+' expression             { $$ = machine.create("+", 2, $1, $3); }
    | expression '*' expression           { $$ = machine.create("*", 2, $1, $3); }
    | expression '-' expression           { $$ = machine.create("-", 2, $1, $3); }
    | expression '/' expression           { $$ = machine.create("/", 2, $1, $3); }
    | expression AND expression           { $$ = machine.create("AND", 2, $1, $3); }
    ;

robot_operation:
    MOVE                { $$ = machine.robot("MOVE"); }                  
    | R_LEFT            { $$ = machine.robot("ROTATE_LEFT"); }           
    | R_RIGHT           { $$ = machine.robot("ROTATE_RIGHT"); }          
    | GET_E             { $$ = machine.robot("GET_E"); }
    ;

unary_operation:
    compare_operation                       { $$ = $1; }
    | '-' expression %prec UMINUS           { $$ = machine.create("UMINUS",1, $2); } 
    | NOT expression                        { $$ = machine.create("NOT", 1, $2); }
    | NOT error                             { $$ = ERROR("It's not a expression", @1.first_line); yyerrok; }
    | SIZE '(' VARIABLE ')'                 { $$ = machine.create("SIZE", 1, machine.id($3)); delete $3; }
    | SIZE '(' VARIABLE error               { $$ = ERROR("Missed ')'", @4.first_line);}
    | SIZE '('')'                           { $$ = ERROR("Missed name variable", @1.first_line); }
    | SIZE '(' error ')'                    { $$ = ERROR("Wrong atribute", @3.first_line); yyerrok; }
    | SIZE error                            { $$ = ERROR("Missed '('", @2.first_line); yyerrok; }
    | GET VARIABLE                          { $$ = machine.create("GET", 1, machine.id_func($2)); delete $2; }
    ;

compare_operation:
    MXCOMP expression               { $$ = machine.create("MXCOMP", 1, $2); }
    | ELCOMP expression             { $$ = machine.create("ELCOMP", 1, $2); }
    | MXTRUE expression             { $$ = machine.create("MXTRUE", 1, $2); }
    | MXFALSE expression            { $$ = machine.create("MXFALSE", 1, $2); }
    ;

statement:
    statement_s ENDLINE                     { $$ = $1; }
    | error ENDLINE                         { $$ = nullptr; }
    | PLEASE statement_s ENDLINE            { $$ = machine.courtesy(1, $2); }
    | PLEASE statement_s THANKS ENDLINE     { $$ = machine.courtesy(2, $2); }
    | statement_s THANKS ENDLINE            { $$ = machine.courtesy(1, $1); }
    | ENDLINE                               { $$ = nullptr; }       
    ;

statement_s:
    compound_statement          { $$ = $1; }
    | definition                { $$ = $1; }
    | unary_statement           { $$ = $1; }
    | function_definition       { $$ = $1; }
    | call_definition           { $$ = $1; }
    | robot_operation           { $$ = $1; }
    | for_loop                  { $$ = $1; }
    | switch_state              { $$ = $1; }
    | PRINT VARIABLE                    { $$ = machine.create("PRINT", 1, machine.id($2)); delete $2; }
    | PRINT error                       { $$ = ERROR("Missed variable", @1.first_line); yyerrok; }
    | VARIABLE '=' expression           { $$ = machine.create("ASSIGN", 2, machine.id($1), $3); delete $1; }
    | VARIABLE error expression         { $$ = ERROR("Missed '='", @1.first_line); yyerrok; delete $1; }
    | appeal_state '=' expression       { $$ = machine.create("ASSIGN_A", 2, $1, $3); } 
    | appeal_state error expression     { $$ = ERROR("Missed '='", @2.first_line); }
    ;


switch_state:
    SWITCH expression BOOL statement_list '[' BOOL statement_list ']'           { $$ = machine.create("SWITCH", 5, $2, machine.constant($3, "BOOL"), $4, machine.constant($6, "BOOL"), $7);} 
    | SWITCH expression BOOL statement_list '[' BOOL statement_list error       { $$ = ERROR("Missed ']'", @8.first_line); yyerrok; }
    | SWITCH expression BOOL statement_list '[' error                           { $$ = ERROR("Missed second flag", @6.first_line); yyerrok; }
    | SWITCH expression BOOL statement_list error BOOL                          { $$ = ERROR("Missed '['", @5.first_line); yyerrok; }
    | SWITCH expression error                                                   { $$ = ERROR("Missed first flag", @3.first_line); yyerrok; }
    | SWITCH error                                                              { $$ = ERROR("Invalid define SWITCH", @2.first_line); yyerrok; }
    ;

appeal_state:
    VARIABLE '[' expression_list ']'                { $$ = machine.appeal("APPEAL_A", $1); delete $1; }
    | VARIABLE '[' error ']'                        { $$ = ERROR("Invalid enumeration",@3.first_line); yyerrok;  delete $1; }
    | VARIABLE '[' ']'                              { $$ = ERROR("Missed enumeration",@3.first_line); yyerrok;  delete $1; }   
    | VARIABLE '[' expression_list error            { $$ = ERROR("Missed '['", @4.first_line); yyerrok; delete $1; }    
    | VARIABLE error                                { $$ = ERROR("Missed '['", @2.first_line); yyerrok; delete $1; }
    ;

for_loop:
    FOR VARIABLE BOUNDARY VARIABLE STEP VARIABLE ENDLINE '(' statement_list ')'                 { $$ = machine.create("FOR", 4, machine.id($2), machine.id($4), machine.id($6), $9); delete $2; delete $4; delete $6; }
    | FOR error                                                                                 { $$ = ERROR("Invalid define loop", @2.first_line); yyerrok; }
    | FOR BOUNDARY VARIABLE STEP VARIABLE ENDLINE '(' statement_list ')'                        { $$ = ERROR("Missed counter", @1.first_line); yyerrok; delete $3; delete $5; }
    | FOR VARIABLE BOUNDARY STEP VARIABLE ENDLINE '(' statement_list ')'                        { $$ = ERROR("Missed edge", @3.first_line); yyerrok; delete $2; delete $5; }
    | FOR VARIABLE BOUNDARY VARIABLE STEP ENDLINE '(' statement_list ')'                        { $$ = ERROR("Missed step", @5.first_line); yyerrok; delete $2; delete $4; }
    | FOR VARIABLE BOUNDARY VARIABLE STEP VARIABLE error                                        { $$ = ERROR("Invalid body", @7.first_line); yyerrok; delete $2; delete $4; delete $6; }
    | FOR VARIABLE BOUNDARY VARIABLE STEP VARIABLE ENDLINE '(' statement_list error             { $$ = ERROR("Missed ')' for loop block", @10.first_line); yyerrok; }
    ;

compound_statement:
    '(' ')'                         { $$ = nullptr; }
    | '(' block_item ')'            { $$ = $2; }
    ;

block_item:
    statement                             { $$ = $1; }
    | block_item statement                { $$ = machine.create("ENDLINE", 2, $1, $2); }
    ;

definition:
    VAR VARIABLE '[' expression_list ']' '=' INTEGER            { $$ = machine.putId($2, $7, "INT"); delete $2; }
    | VAR VARIABLE '[' expression_list ']' '=' BOOL             { $$ = machine.putId($2, $7, "BOOL"); delete $2; }
    | VAR VARIABLE '=' INTEGER                                  { $$ = machine.putId($2, $4, "INT"); delete $2; }
    | VAR VARIABLE '=' BOOL                                     { $$ = machine.putId($2, $4, "BOOL"); delete $2; }
    | VAR VARIABLE '[' expression_list ']' '=' error            { $$ = ERROR("Missed literal", @7.first_line); yyerrok; delete $2; }
    | VAR VARIABLE '=' error                                    { $$ = ERROR("Missed literal", @4.first_line); yyerrok; delete $2; }
    | VAR VARIABLE '[' expression_list ']' error                { $$ = ERROR("Missed '='", @6.first_line); yyerrok; delete $2; }
    | VAR VARIABLE '[' expression_list error '=' INTEGER        { $$ = ERROR("Missed ']' or ','", @5.first_line); yyerrok; delete $2; }
    | VAR VARIABLE '[' expression_list error '=' BOOL           { $$ = ERROR("Missed ']' or ','", @5.first_line); yyerrok; delete $2; }
    | VAR VARIABLE '[' error ']' '=' INTEGER                    { $$ = ERROR("Wrong enumeration size", @4.first_line); yyerrok; delete $2; }
    | VAR VARIABLE '[' error ']' '=' BOOL                       { $$ = ERROR("Wrong enumeration size", @4.first_line); yyerrok; delete $2; }
    | VAR VARIABLE error                                        { $$ = ERROR("Missed '[' or '='", @3.first_line); yyerrok; delete $2; } 
    | VAR error '[' expression_list ']' '=' INTEGER             { $$ = ERROR("Missed name", @2.first_line); yyerrok;}
    | VAR error '[' expression_list ']' '=' BOOL                { $$ = ERROR("Missed name", @2.first_line); yyerrok;}
    | VAR error                                                 { $$ = ERROR("Undefine variable", @2.first_line); yyerrok; }
    ;

unary_statement:
    LOGITIZE VARIABLE                           { $$ = machine.create("LOGITIZE", 1, machine.id($2)); delete $2; }
    | DIGITIZE VARIABLE                         { $$ = machine.create("DIGITIZE", 1, machine.id($2)); delete $2; }
    | REDUCE VARIABLE '[' INTEGER ']'           { $$ = machine.create("REDUCE", 2, machine.id($2), machine.constant($4, "INT")); delete $2; }
    | EXTENED VARIABLE '[' INTEGER ']'          { $$ = machine.create("EXTENED", 2 , machine.id($2), machine.constant($4, "INT")); delete $2; }
    | REDUCE VARIABLE '[' INTEGER error         { $$ = ERROR("Missed ']'", @5.first_line); yyerrok;  delete $2;}
    | REDUCE VARIABLE '[' error ']'             { $$ = ERROR("Missed number", @4.first_line); yyerrok; delete $2; }
    | REDUCE VARIABLE '[' error                 { $$ = ERROR("Invalid argunemt", @4.first_line); yyerrok; delete $2; }
    | REDUCE VARIABLE error                     { $$ = ERROR("Missed '['", @3.first_line); yyerrok; delete $2; }
    | REDUCE error                              { $$ = ERROR("Missed variable", @2.first_line); yyerrok;}
    | EXTENED VARIABLE '[' INTEGER error        { $$ = ERROR("Missed ']'", @5.first_line); yyerrok; delete $2; }
    | EXTENED VARIABLE '[' error ']'            { $$ = ERROR("Missed number", @4.first_line); yyerrok; delete $2; }
    | EXTENED VARIABLE '[' error                { $$ = ERROR("Invalid argunemt", @4.first_line); yyerrok; delete $2; }
    | EXTENED VARIABLE error                    { $$ = ERROR("Missed '['", @3.first_line); yyerrok; delete $2; }
    | EXTENED error                             { $$ = ERROR("Missed variable", @2.first_line); yyerrok;}
    ;
%%


void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

void COMP_ERROR(const char* exept)
{
    std::cout << "Crash: " << exept << '\n';
    machine.clear_sys();
    exit(1);
}

Vertex* ERROR(const std::string& type, int line)
{
    std::cerr << "Error syntax at line -> " << line << ": " << type << '\n';
    errorFlag = true;
    return nullptr;
}


void freeNode(Vertex *node)
{   
    if (node == nullptr) 
        return;

    Node *ptr = nullptr;
 

    if((ptr = dynamic_cast<Node*>(node)))
    {
        if (ptr == nullptr)
            return;

        for(int i = 0; i < ptr->leafs.size(); ++i)
        {
                freeNode(ptr->leafs[i]);
        }
    }
    if (node) 
        delete node;
}


//algorithm
int main(void) {
    #if YYDEBUG
    yydebug = 1;
    yy_flex_debug = 1;
    #endif
    yyin = fopen ("./test2.txt", "r");
    yyparse();
    fclose (yyin);
    return 0;
}
