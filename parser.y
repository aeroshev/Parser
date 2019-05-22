%{
    #define YYDEBUG 1
    #include <string>
    #include <map>
    #include <vector>
    #include <fstream>
    #include <iostream>
    #include <random>
    #include <limits>
    #include "Prog.h"

    extern FILE * yyin;

    int yylex(void);
    void yyerror(char *s);
// 1 - Wall
// 0 - empty
// 2 - exit
//rebulid for 3d variable

template <class T>
T getRandom()
{
    static std::random_device device;
    static std::uniform_int_distribution<T> dist(1);
    return dist(device);
}


class enum Cell
{
    Empty,
    Wall,
    Exit
};

class Robot
{
private:
    std::vector<std::vector<uint64_t> > map;
    std::pair<uint64_t, uint64_t> coordinate;
    std::pair<int, int> gaze_direction;

    constexpr uint16_t edge_hysteria = 10;
    constexpr uint16_t level_hysteria = 0;

    
    static constexpr std::pair<int, int> Down = std::make_pair(0, 1);
    static constexpr std::pair<int, int> Right = std::make_pair(1, 0);
    static constexpr std::pair<int, int> Up = std::make_pair(0, -1);
    static constexpr std::pair<int, int> Left = std::make_pair(-1, 0);

public:
    Robot(const std::pair<uint64_t, uint64_t>& coor, const std::pair<uint64_t, uint64_t>& dir, const std::vector<std::vector<uint64_t> > map_out):
    map(map_out),
    coordinate(coor),
    gaze_direction(dir)
    {}

    Cell move()
    {
        coordinate += gaze_direction;
        if (map[gaze_direction.first][gaze_direction.second] == Cell::Wall)
        {
            return Cell::Wall;
        }
        if (map[gaze_direction.first][gaze_direction.second] == Cell::Exit)
        {
            return Cell::Exit;
        }

        return Cell::Empty;
    }

    void rotate_left()
    {
        switch(gaze_direction)
        {
            case Down:
            {
                gaze_direction = Right;
                break;
            }
            case Right:
            {
                gaze_direction = Up;
                break;
            }
            case Up:
            {
                gaze_direction = Left;
                break;
            }
            case Left:
            {
                gaze_direction = Down;
                break;
            }
        }
    }
    void rotate_right()
    {
        switch(gaze_direction)
        {
            case Down:
            {
                gaze_direction = Left;
                break;
            }
            case Left:
            {
                gaze_direction = Up;
                break;
            }
            case Up:
            {
                gaze_direction = Right;
                break;
            }
            case Right:
            {
                gaze_direction = Down;
                break;
            }
        }
    }

    Descriptior_Value get_environment()
    {

    }
};



class Label
{
public:
	
    Descriptior_Value* value;
    bool flag;
    int constant;
	
	Result(){}
	Result(int a, string s, string type) : IVAL(a), ISTR(s), ITYPE(type){}
	
};

        class Vertex 
        { 
        public:
            std::string type;

            Vertex(const std::string& name):
            type(name)
            {}

            ~virtual Vertex(){}
        };

        class _Id : public Vertex
        {
            std::string name;
        public:

            _Id(const std::string& type, const std::string& name):
            Vertex(type),
            name(name)
            {}
        };
        
        class _Value : public Vertex
        {
            int value;
        public:

            _Value(const std::string& name, int value):
            Vertex(name),
            value(value)
            {}
        };

        class funcall : public Vertex
        {
            std::string func_name;
            std::list<std::string> args;

            funcall(const std::string& type, const std::string& func_name, const std::sting& decl, const std::list<std::string>& decl_list):
            Vertex(type),
            func_name(func_name),
            args(decl_list)
            {
                args.push_back(decl);
            }
        };

        class Node : public Vertex
        {
            int count_leaf;
	        std::vector<Vertex *> leafs;	
        public:
            Node(int count_leaf, const std::vector<Vertex *> vec):
            count_leaf(count_leaf),
            leafs(vec)
            {}
        };

        class Descriptior_Value
        {
        public:
            int dimension;
            int literal;
	        std::vector< std::vector<int> > value;
            std::list<int>& enum_;
            std::string type;


            Descriptior_Value(int dim, const std::list<int>& enum_, int literal. const std::string& type):
            dimension(dim),
            literal(literal),
            enum_(enum_),
            type(type)
            {}

        };

        class Descriptior_func
        {
        public:
            std::list<std::string> args;
            Vertex* body;
            Vertex* end;
            Descriptior_Value result;

            Descriptior_func(const std::string& decl, const std::list<std::string>& decl_list, Vertex* stmt_, Vertex* end):
            args(decl_list),
            body(stmt_),
            end(end)
            {args.push_front(decl);}
        }

    class MAIN_CLASS
    {
    public:
        std::map<std::string, Descriptior_func *> funcTable;
        std::map<std::string, std::map<std::string, Descriptior_Value *> idTable;

        std::vector<Descriptior_Value *> temp_idTable;

        std::string VISION;
        std::string PREV_VISION;

        Vertex* putId(const std::string& name, const std::list<int>& enumeration, int literal, const std::string& type)
        {
            Descriptior_Value * object = new Descriptior_Value(enumeration.size(), enumeration, literal, type);

            temp_idTable.push_back(object);

            Vertex * node = new _Id("VAR", name);

            return node;
        }

        void putFunc(const std::string& name, const std::string& decl, const std::list<std::string>& decl_list, Vertex* stmt, Vertex* end)
        {
            Vertex* node = nullptr;

            funcTable[name] = new Descriptior_func(decl, decl_list, stmt, end);
        }

        	Vertex* create(const std::string& type, int count, ...)
            {
                std::vector<Vertex *> leafs;

                va_list vl;

                va_start(vl, count);
                for (int i = 0; i < count; i++)
                {
                    Vertex* ptr = va_arg(vl, Vertex*);			
                    leafs.push_back(ptr);				
                }	
                
                Vertex* node;
                node = new Node(type, count, leafs);		

                va_end (vl);

                return node;
            }

        Vertex* id(const std::string& name)//
        {
            Vertex* node = new _Id("ID", name);

            return node;
        }

        Vertex* constant(int value)//
        {
            Vertex* node = new _Value("VALUE", value);

            return node; 
        }

Label execute(Vertex * vertex)
{
		
		Result res(0, "UNDEF", v->_type);
		
		if(vertex->type == "ASSIGN")
		{

			Node* V_Node = static_cast<Node*>(vertex);

			Lable config_variable = execute(V_Node->leafs[0]);

            Label config_expression = execute(V_Node->leafs[1]);
			
			while(Ver_Des)
			{
				
				Node *ADR = static_cast<Node*>(Ver_Des->leafs[1]);
				string name = static_cast<_Id*>(ADR->leafs[0])->name;
				Node *ind = static_cast<Node*>(ADR->leafs[1]);
				 

				 
				Descriptor *D = nullptr;
					
				if(Id_Table[VISION].find(name) != Id_Table[VISION].end())
					D = Id_Table[VISION][name];
				else if(Id_Table["GLOBAL"].find(name) != Id_Table["GLOBAL"].end())
					D = Id_Table["GLOBAL"][name];
				else
					COMP_ERROR("ID DID NOT DECLARED IN THIS SCOPE");
			
				if(D->_type == "INT")
				{
					Descr_Value*D_V = static_cast<Descr_Value*>(D);
					
					if(D->_const)
						COMP_ERROR("ATTEMPT TO CHANGE CONSTANT ID");
					
					if(!D_V->Dimension.size())
						D_V->val = Complete(Ver_Expr->leafs[1]).IVAL;
					else
					{
						vector<int> mas;
						while (ind)
						{
							mas.insert(mas.begin(), Complete(ind->leafs[1]).IVAL);
							ind = static_cast<Node*>(ind->leafs[0]);
						}
						
						D_V->Index(mas)->val = Complete(Ver_Expr->leafs[1]).IVAL;
					}
				}

				Ver_Des = static_cast<Node*>(Ver_Des->leafs[0]);
			}
		}		

		if (vertex->type == "VAR")//-----------------
		{	
			_Id* VarNode= static_cast<_Id*>(vertex);
            std::string name = VarNode.name;
			
			if(Id_Table[VISION].find(name) != Id_Table[VISION].end())
				COMP_ERROR("ID ALREADY DECLARED IN THIS SCOPE");

            auto find_ = temp_idTable.find(name);

            if (find_ == temp_idTable.end())
                COMP_ERROR("FATAL ERROR");

            size_t dim1 = find_->enum_.front();
            find_->enum_.pop_front();
            size_t dim2 = find_->enum_.front();
            find_->enum_.pop_front();

            for (size_t i = 0; i != dim1; i++)
            {
                find_->value.push_back(std::vector<int> (dim2));
                for (size_t j = 0; j != dim2; j++)
                {
                    find_->value[i][j] = literal; 
                }
            }

            auto result = Id_Table[VISION].insert(std::make_pair(name, *find_));
            if (!result->second)
                COMP_ERROR("FATAL ERROR");
        }	
		if (vertex->type == "+")//?
		{	
			Node* V_Node = static_cast<Node*>(vertex);

            Label config_1 = execute(V_Node->leafs[0]);
			Label config_2 = execute(V_Node->leafs[1]);

            if (config_1.Descriptior_Value == nullptr || config_2.Descriptior_Value == nullptr)
                COMP_ERROR("one of the elements is not a variable");

            Label config;
            size_t dim1, dim2;

            if (config_1.enum_.front() <= config_2.enum_.front())
                dim1 = config_1.enum_.front();
            else
                dim1 = config_2.enum_.front();
                
            
            if (config_1.value[0].size() <= config_2.value[0].size())//repare
                dim2 = config_1.value[0].size();
            else
                dim2 = config_2.value[0].size()

            for (size_t i = 0; i != dim1; i++)
            {
                config.value.push_back(std::vector<int> (dim2));

                for(size_t j = 0; j != dim2; j++)
                {
                    config.value[i][j] = config_1.value[i][j] + config_2.value[i][j];
                }
            }

            return config;		
        }
		if (vertex->type == "*")//?
		{	
			Node* V_Node = static_cast<Node*>(vertex);

            Label config_1 = execute(V_Node->leafs[0]);
			Label config_2 = execute(V_Node->leafs[1]);

            if (config_1.Descriptior_Value == nullptr || config_2.Descriptior_Value == nullptr)
                COMP_ERROR("one of the elements is not a variable");

            Label config;
            size_t dim1, dim2;

            if (config_1.enum_.front() <= config_2.enum_.front())
                dim1 = config_1.enum_.front();
            else
                dim1 = config_2.enum_.front();
                
            
            if (config_1.value[0].size() <= config_2.value[0].size())//repare
                dim2 = config_1.value[0].size();
            else
                dim2 = config_2.value[0].size()

            for (size_t i = 0; i != dim1; i++)
            {
                config.value.push_back(std::vector<int> (dim2));

                for(size_t j = 0; j != dim2; j++)
                {
                    config.value[i][j] = config_1.value[i][j] * config_2.value[i][j];
                }
            }

            return config;	
        }
        if (vertex->type == "-")//?
		{	
			Node* V_Node = static_cast<Node*>(vertex);

            Label config_1 = execute(V_Node->leafs[0]);
			Label config_2 = execute(V_Node->leafs[1]);

            if (config_1.Descriptior_Value == nullptr || config_2.Descriptior_Value == nullptr)
                COMP_ERROR("one of the elements is not a variable");

            Label config;
            size_t dim1, dim2;

            if (config_1.enum_.front() <= config_2.enum_.front())
                dim1 = config_1.enum_.front();
            else
                dim1 = config_2.enum_.front();
                
            
            if (config_1.value[0].size() <= config_2.value[0].size())//repare
                dim2 = config_1.value[0].size();
            else
                dim2 = config_2.value[0].size()

            for (size_t i = 0; i != dim1; i++)
            {
                config.value.push_back(std::vector<int> (dim2));

                for(size_t j = 0; j != dim2; j++)
                {
                    config.value[i][j] = config_1.value[i][j] - config_2.value[i][j];
                }
            }

            return config;	
        }
        if (vertex->type == "/")//?
		{	
			Node* V_Node = static_cast<Node*>(vertex);

            Label config_1 = execute(V_Node->leafs[0]);
			Label config_2 = execute(V_Node->leafs[1]);

            if (config_1.Descriptior_Value == nullptr || config_2.Descriptior_Value == nullptr)
                COMP_ERROR("one of the elements is not a variable");

            Label config;
            size_t dim1, dim2;

            if (config_1.enum_.front() <= config_2.enum_.front())
                dim1 = config_1.enum_.front();
            else
                dim1 = config_2.enum_.front();
                
            
            if (config_1.value[0].size() <= config_2.value[0].size())//repare
                dim2 = config_1.value[0].size();
            else
                dim2 = config_2.value[0].size()

            for (size_t i = 0; i != dim1; i++)
            {
                config.value.push_back(std::vector<int> (dim2));

                for(size_t j = 0; j != dim2; j++)
                {
                    if (config_2.value[i][j != 0])
                        config.value[i][j] = config_1.value[i][j] * config_2.value[i][j];
                    else
                        COMP_ERROR("TRY DIDIVED ON ZERO");
                }
            }

            return config;	
        }			
		if (vertex->type == "MXCOMP")
		{	
			Node* V_Node = static_cast<Node*>(vertex);
			
			Label config = execute(V_Node->leafs[0]);

            if (config.value == nullptr)
                COMP_ERROR("DON'T HAVE VARIABLE");

            size_t quantity;

            for (size_t i = 0; i != config.value.size(); i++)
            {
                for (size_t j = 0; j != config.value[i].size(); j++)
                {
                    if (config.value[i][j] != 0)
                        quantity++;
                }
            }

            if (quantity > config.value.size() * config.value[0].size())
                config.flag = "true";
            else
                config.flag = "false";

            return config;	
        }

        if (vertex->type == "ELCOMP")
        {
            //?
        }
		if(vertex->type == "NOT")
		{					
			Node* V_Node = static_cast<Node*>(v);

            Label config = execute(V_Node->leafs[0]);

            if (config.value == nullptr)
                COMP_ERROR("DON'T HAVE VARIABLE");

            for (size_t i = 0; i != config.value.size(); i++)
            {
                for (size_t j = 0; j != config.value[i].size(); j++)
                {
                    if (config.value[i][j] != 0)
                        config.value[i][j] = 0;
                    else
                        config.value[i][j] = 1;
                }
            }

            return config;	
        }
		if(v->_type == "AND")
		{		
            Node* V_Node = static_cast<Node*>(vertex);

            Label config_1 = execute(V_Node->leafs[0]);
			Label config_2 = execute(V_Node->leafs[1]);

            if (config_1.Descriptior_Value == nullptr || config_2.Descriptior_Value == nullptr)
                COMP_ERROR("one of the elements is not a variable");

            for (size_t i = 0; i != config.value.size(); i++)
            {
                for (size_t j = 0; j != config.value[i].size(); j++)
                {
                    config.value[i][j] = config_1.value[i][j] && config_2.value[i][j]
                }
            }
            
            return config;
        }	
		if (vertex->type == "MXTRUE")
        {
            Node* V_Node = static_cast<Node*>(vertex);
			
			Label config = execute(V_Node->leafs[0]);

            if (config.value == nullptr)
                COMP_ERROR("DON'T HAVE VARIABLE");

            size_t quantity;

            for (size_t i = 0; i != config.value.size(); i++)
            {
                for (size_t j = 0; j != config.value[i].size(); j++)
                {
                    if (config.value[i][j] == "true" || config.value[i][j] == 1)
                        quantity++;
                }
            }

            if (quantity > config.value.size() * config.value[0].size())
                config.flag = "true";
            else
                config.flag = "false";

            return config;	
        }
        if (vertex->type == "MXFALSE")
        {
            Node* V_Node = static_cast<Node*>(vertex);
			
			Label config = execute(V_Node->leafs[0]);

            if (config.value == nullptr)
                COMP_ERROR("DON'T HAVE VARIABLE");

            size_t quantity;

            for (size_t i = 0; i != config.value.size(); i++)
            {
                for (size_t j = 0; j != config.value[i].size(); j++)
                {
                    if (config.value[i][j] == "false" || config.value[i][j] == 0)
                        quantity++;
                }
            }

            if (quantity > config.value.size() * config.value[0].size())
                config.flag = "true";
            else
                config.flag = "false";

            return config;
        }
        if (vertex->type == "ID")
        {
            Label config;
            _Id * V_Node = static_cast<_Id *>(vertex);

            auto element = Id_Table[VISION].find(V_Node->name);
            if (element != Id_Table[VISION].end())
            {
                config.value = *element;
            }

            return config;
        }
        if (vertex->type = "VALUE")
        {
            Label config;
            _Value * V_Node = static_cast<_Id *>(vertex);

            config.constant = V_Node->value;
        }
		if(vertex->type == "FOR")
		{	
            Node* V_Node = static_cast<Node*>(vertex);

            Label config_counter = execute(V_Node->leafs[0]);
            Label config_edge = execute(V_Node->leafs[1]);
            Label config_step = execute(V_Node->leafs[2]);

            if (config_counter.value.size() != config_edge.value.size())
                COMP_ERROR("");
            if (config_counter.value.size() != config_step.value.size())
                COMP_ERROR("");
            if (config_edge.value.size() != config_step.value.size())
                COMP_ERROR("");

            while(1)
            {
                for (size_t i = 0; i != config_counter.value.size(); i++)
                {
                    if (config_counter[i][j] )
                    for (size_t j = 0; j != config_counter.value[i].size(); j++)
                    {
                        //?
                    }
                }
            }
		}
        if (vertex->type == "SWITCH")
        {
            Node* V_Node = static_cast<Node*>(vertex);

            Label config_logic_expr = execute(V_Node->leafs[0]);
            Label config_bool_1 = execute(V_Node->leafs[1]);
            Label config_bool_2 = execute(V_Node->leafs[4]);

            Label config;

            if (config_logic_expr.flag == config_bool_1.flag)
                config = execute(V_Node->leafs[2]);
            if (config_logic_expr.flag == config_bool_2.flag)
                config = execute(V_Node->leafs[5]);

            return config;
        }
		if(vertex->type == "DO")
		{	
            funcall* call_node = static_cast<funcall*>(vertex);

            //проверяем существрвание такой функции
            auto ptr_func = funcTable.find(call_node->func_name);
            if (ptr_func == funcTable.end())
                COMP_ERROR("NOT FOUND FUNCTION");

            //проверяем количество аргументов в дескрипторе функции и взыова DO 
            if (ptr_func->second->args.size() != call_node->args.size())
                COMP_ERROR("number of arguments does not match");

            //проверить, есть ли данные аргументы в вызове DO в предыдущей области видимости

            PREV_VISION = VISION
            VISION = ptr_func->first;

            //выполнить тело функции

            //выполнить тело RESULT

            

            
            
			// Node* V_Call = static_cast<Node*>(v);
			
			// string name = (static_cast<_Id*>(V_Call->leafs[0]))->name;
			// if(name == "MAIN")
			// 	COMP_ERROR("CAN NOT CALL FUNCTION MAIN");
			// if(Func_Table.find(name) == Func_Table.end())
			// 	COMP_ERROR("FUNCTION DID NOT FIND");
			// string old = VISION;
			// VISION = name;
			
			// Complete(Func_Table[name]);	
			// for(auto i = Id_Table[name].begin(); i != Id_Table[name].end(); i++)
			// 	delete i->second;
			// Id_Table.erase(name);	

			// VISION = old;
		}
        if (vertex->type == "GET")
        {

        }
        if (vertex->type == "SIZE")
        {
            Node* V_Node = static_cast<Node*>(vertex);

            Label config = execute(V_node->leafs[0]);

            if (config.value == nullptr)
                COMP_ERROR("DONT'T HAVE VALUE");

            config.constant = 2;//?

            return config;
        }


        
}

};

    MAIN_CLASS machine;



%}


%union{
    int iValue;
    bool iBool;
    std::string iName;
    std::list<std::string> args;
    std::list<int> enum;
    Vertex * nPtr;
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


%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%type <nPtr>  function_definition call_definition t  arithmetic_operator arithmetic_expression logic_expression expression statement statement_list
%type <args> declaration_lis
%type <enum> enumeration_list
%type <iName> declaration

%%
program:
        statement_list          { machine.execute($1); }
        ;

statement_list:
        statement_list statement ENDLINE          { $$ = machine.create("ENDLINE", 2, $1, $2); }
        | /*NULL*/         { init(); $$ = 0; }
        ;

function_definition:
        TASK VARIABLE declaration ',' '[' declaration_list ']' statement_list end_           { machine.putFunc($2, $3, $6, $8, $9); }
        | TASK VARIABLE declaration statement_list end_          { machine.putFunc($2, $3, nullptr, $4, $5); }
        ;

end_:
        RESULT VARIABLE         { $$ = machine.create("RESULT", 1, machine.id($2)); }

call_definition:
        DO VARIABLE declaration ',' '[' declaration_list ']'            { $$ = new funcall("DO", $2, $3, $6); }
        | DO VARIABLE declaration           { $$ = new funcall("DO", $2, $3, nullptr); }
        ;

declaration_list:
        VARIABLE            { $$.clear(); $$.push_back($1); }
        | declaration_list ',' VARIABLE         { $$ = $1; $$.push_back($3); }
        ;

enumeration_list:
        INTEGER          { $$.clear(); $$.push_back($1); }
        | enumeration_list ',' INTEGER           { $$ = $1; $$.push_back($3); }
        ;

arithmetic_expression:
    INTEGER         { $$ = machine.constant($1); }
    | VARIABLE          { $$ = machine.id($1); }
    | arithmetic_expression "+" arithmetic_expression           { $$ = machine.create("+", 2, $1, $3); }
    | arithmetic_expression "*" arithmetic_expression           { $$ = machine.create("*", 2, $1, $3); }
    | arithmetic_expression "-" arithmetic_expression           { $$ = machine.create("-", 2, $1, $3); }
    | arithmetic_expression "/" arithmetic_expression           { $$ = machine.create("/", 2, $1, $3); }
    | MXCOMP arithmetic_expression          { $$ = machine.create("MXCOMP", 1, $2); }
    | ELCOMP arithmetic_expression          { $$ = machine.create("ELCOMP", 1, $2); }
    | '-' arithmetic_expression %prec UMINUS        { $$ = new unary("UMINUS", $2); }    //
    ;

logic_expression:
    BOOL            { $$ = machine.constant($1); }
    | VARIABLE          { $$ = achine.id($1); }
    | NOT logic_expression          { $$ = machine.create("NOT", 1, $2); }
    | logic_expression AND logic_expression         { $$ = machine.create("AND", 2, $1, $3); }
    | MXTRUE logic_expression           { $$ = machine.create("MXTRUE", 1, $2); }
    | MXFALSE logic_expression          { $$ = machine.create("MXFALSE", 1, $2); }
    ;

expression:
    arithmetic_expression           { $$ = $1; }
    | logic_expression          { $$ = $1; }
    | LOGITIZE VARIABLE         { $$ = machine.create("LOGITIZE", 1, machine.id($2)); }
    | DIGITIZE VARIABLE         { $$ = machine.create("DIGITIZE", 1, machine.id($2)); }
    | REDUCE VARIABLE '[' INTEGER ']'           { $$ = machine.create("REDUCE", 2, machine.id($2), machine.constant($4)); }
    | EXTENED VARIABLE '[' INTEGER ']'          { $$ = machine.create("EXTENED", 2 , machine.id($2), machine.constant($4)); }
    | '(' expression ')'            { $$ = $2; }
    | SIZE '(' VARIABLE ')'         { $$ = machine.create("SIZE", 1, machine.id($3)); }
    | VARIABLE '[' declaration_list ']'         { $$ = machine.appeal("APPEAL", $1, $3); }//?
    | MOVE          {}                  
    | R_LEFT            {}           
    | R_RIGHT           {}          
    | GET_E         {}
    ;

statement:
    expression          { $$ = $1; }
    | VARIABLE '=' expression           { $$ = machine.create("ASSIGN", 2, machine.id($1), $3); }
    | VAR VARIABLE '[' enumeration_list ']' '=' INTEGER            { machine.putId($2, $4, $7, "INT"); }
    | function_definition           { $$ = $1; }
    | FOR VARIABLE BOUNDARY VARIABLE STEP VARIABLE statement_list           { $$ = machine.create("FOR", 4, machine.id($2), machine.id($4), machine.id($6), $7); }
    | SWITCH logic_expression BOOL statement_list '[' BOOL statement_list ']'           { $$ = machine.create("SWITCH", 5, $2, machine.constant($3), $4, machine.constant($6), $7); }
    | call_definition           { $$ = $1; }
    | GET VARIABLE          { $$ = machine.create("GET", 1, machine.id($2); }
    ;
%%

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}



int main(void) {
    #if YYDEBUG
    yydebug = 1;
    #endif
    yyin = fopen ("./test.txt", "r");
    yyparse();
    fclose (yyin);
    return 0;
}
