
%{
    #include <iostream>
    #include <string>
    #include <list>
    #include <cstring>
    #include <stdexcept>
    #include <cmath>
    #include "Prog.h"
    #include "parser.tab.h"

        
    void yyerror(char *);
    std::string* buffer;
    bool flag;

    inline int OCTAL_TO_DEC(const std::string& OCTAL)
    {
        int k;
        int result = 0;
        size_t len_OCTAL = OCTAL.size() - 1;
        size_t len = OCTAL.size();
        
        for (size_t i = 0; i != len; i++)
        {
            switch (OCTAL[i])
            {
                case '1': k = 1; break;
                case '2': k = 2; break;
                case '3': k = 3; break;
                case '4': k = 4; break;
                case '5': k = 5; break;
                case '6': k = 6; break;
                case '7': k = 7; break;
                case '0': k = 0; break;
                    
                default:
                    throw std::bad_cast();
            }
            
            result += k * std::pow(8,len_OCTAL);
            len_OCTAL--;
        }
        
        return result;
    }

    inline int HEX_TO_DEC(const std::string& hex, bool& flag)
    {
        int k;
        int result = 0;
        size_t len_hex = hex.size() - 1;
        size_t len = hex.size();
        
        for (size_t i = 0; i != len; i++)
        {
            switch (hex[i])
            {
                case 'A': k = 10; flag = 1; break;
                case 'B': k = 11; flag = 1; break;
                case 'C': k = 12; flag = 1; break;
                case 'D': k = 13; flag = 1; break;
                case 'E': k = 14; flag = 1; break;
                case 'F': k = 15; flag = 1; break;
                case '1': k = 1; break;
                case '2': k = 2; break;
                case '3': k = 3; break;
                case '4': k = 4; break;
                case '5': k = 5; break;
                case '6': k = 6; break;
                case '7': k = 7; break;
                case '8': k = 8; break;
                case '9': k = 9; break;
                case '0': k = 0; break;
                    
                default:
                    throw std::bad_cast();
            }
            
            result += k * std::pow(16,len_hex);
            len_hex--;
        }
        
        return result;
    }

%}

%option noyywrap
%option yylineno
%x HEX 

%%

[/][/].*\n      ; /* comment*/

("TRUE"|"true")         {
                            yylloc.last_line = yylloc.first_line = yylineno;
                            yylval.iBool = true;
                            return BOOL;
                        }

("FALSE"|"false")       {
                            yylloc.last_line = yylloc.first_line = yylineno;
                            yylval.iBool = false;
                            return BOOL;
                        }

"PLEASE"            { yylloc.last_line = yylloc.first_line = yylineno; return PLEASE; }
"THANKS"            { yylloc.last_line = yylloc.first_line = yylineno; return THANKS; }
"VAR"               { yylloc.last_line = yylloc.first_line = yylineno; return VAR; }
"LOGITIZE"          { yylloc.last_line = yylloc.first_line = yylineno; return LOGITIZE; }
"DIGITIZE"          { yylloc.last_line = yylloc.first_line = yylineno; return DIGITIZE; }
"SIZE"              { yylloc.last_line = yylloc.first_line = yylineno; return SIZE; }
"REDUCE"            { yylloc.last_line = yylloc.first_line = yylineno; return REDUCE; } 
"EXTENED"           { yylloc.last_line = yylloc.first_line = yylineno; return EXTENED; }
"NOT"               { yylloc.last_line = yylloc.first_line = yylineno; return NOT; } 
"AND"               { yylloc.last_line = yylloc.first_line = yylineno; return AND; }
"MXTRUE"            { yylloc.last_line = yylloc.first_line = yylineno; return MXTRUE; }
"MXFALSE"           { yylloc.last_line = yylloc.first_line = yylineno; return MXFALSE; }
"FOR"               { yylloc.last_line = yylloc.first_line = yylineno; return FOR; }
"BOUNDARY"          { yylloc.last_line = yylloc.first_line = yylineno; return BOUNDARY; }
"STEP"              { yylloc.last_line = yylloc.first_line = yylineno; return STEP; }
"SWITCH"            { yylloc.last_line = yylloc.first_line = yylineno; return SWITCH; }
"DO"                { yylloc.last_line = yylloc.first_line = yylineno; return DO; }
"GET"               { yylloc.last_line = yylloc.first_line = yylineno; return GET; }
"TASK"              { yylloc.last_line = yylloc.first_line = yylineno; return TASK; }
"ROTATE RIGHT"      { yylloc.last_line = yylloc.first_line = yylineno; return R_RIGHT; }
"ROTATE LEFT"       { yylloc.last_line = yylloc.first_line = yylineno; return R_LEFT; }
"GET ENVIRONMENT"   { yylloc.last_line = yylloc.first_line = yylineno; return GET_E; }
"MOVE"              { yylloc.last_line = yylloc.first_line = yylineno; return MOVE; }
"FINDEXIT"          return FINDEXIT;
"RESULT"            { yylloc.last_line = yylloc.first_line = yylineno; return RESULT; }
"PRINT"             { yylloc.last_line = yylloc.first_line = yylineno; return PRINT; }
[\n]                return ENDLINE;


"MXEQ"|"MXLT"|"MXGT"|"MXLTE"|"MXGTE"        return MXCOMP;
"ELEQ"|"ELLT"|"ELGT"|"ELLTE"|"ELGTE"        return ELCOMP;

[a-zA-Z_][a-zA-Z0-9_]*      { 
                                yylloc.last_line = yylloc.first_line = yylineno;
                                int leng = std::strlen(yytext);
                                yylval.iName = (char*)calloc((leng+1),sizeof(char));
                                std::strcpy(yylval.iName , yytext);
                                yylval.iName[leng] = '\0';

                                return VARIABLE;
                            }

[1-7]([1-7])*           {
                            yylloc.last_line = yylloc.first_line = yylineno;
                            yylval.iValue = std::atoi(yytext);
                   
                            return INTEGER;
                        }


[0]+[1-7]([0-7]*)      {
                            yylloc.last_line = yylloc.first_line = yylineno;
                            buffer = new std::string(yytext);

                         
                            int dec = -1;
                            try
                            {
                                dec = OCTAL_TO_DEC(*buffer);
                            }
                            catch(std::bad_cast&)
                            {
                                std::cerr << "Bad cast OCTAL to DEC" << '\n';
                                exit(1);
                            }
                            delete buffer;

                            yylval.iValue = dec;
                          
                            return INTEGER;
                        }
[0]+[1-9]([0-9]*)       {
                            yylloc.last_line = yylloc.first_line = yylineno;
                            yylval.iValue = std::atoi(yytext);
                  
                            return INTEGER;
                        }
    


"0x"        { BEGIN(HEX); }
<HEX>{
    [A-F0-9]+       {
                        yylloc.last_line = yylloc.first_line = yylineno;
                        buffer = new std::string(yytext);

                        int dec = -1;
                        try
                        {
                            dec = HEX_TO_DEC(*buffer, flag);
                        }
                        catch(std::bad_cast&)
                        {
                            std::cerr << "Bad cast HEX to DEC" << '\n';
                            exit(1);
                        }
                        delete(buffer);
                        

                        yylval.iValue = dec;

                        BEGIN(INITIAL);
                        return INTEGER;
                    }
    .               { std::cerr << "Undefine symbol in HEX" << '\n'; }
}



[A-F0-9]+           {
                        yylloc.last_line = yylloc.first_line = yylineno;
                        buffer = new std::string(yytext);


                        flag = 0;
                        int dec = -1;    
                        try{
                            dec = HEX_TO_DEC(*buffer, flag);
                        }
                        catch(std::bad_cast&)
                        {
                            std::cerr << "Bad cast HEX to DEC" << '\n';
                            exit(1);
                        }
                        if (!flag)
                        {
                            yyerror("Don't have A-F");
                        }
                        delete buffer;
                        

                        yylval.iValue = dec;
                        
                        return INTEGER;
                    }  

      

[()=+*/\[\],]       {
                        yylloc.last_line = yylloc.first_line = yylineno;
                        return *yytext;
                    }
"-"                 {
                        yylloc.last_line = yylloc.first_line = yylineno;
                        return *yytext;
                    }



[\ \t]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
