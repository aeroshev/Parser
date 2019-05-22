
%{
#include <stdlib.h>
#include <string>
#include "parser.tab.h"
#include "Prog.h"
void yyerror(char *);
/* update lex number*/
std::string buffer;
%}

%option noyywrap

%%

[/][/].*\n      ; /* comment*/

[a-zA-Z_][a-zA-Z0-9_]*  { 
                            yylval.iName = yytext;
                            return VARIABLE;
                        }

[0][0-7]+       {
                    buffer = yytext;
                    //перевод в 10-ный
                    yylval.Octal = buffer;
                    return OCTAL;
                }

"0x"[A-F0-9]+      {

                    buffer = yytext;
                    //перевод в 10-ный
                    yylval.Hex = buffer;
                    return HEX;
                }

[A-F0-9]+           {
                        buffer = yytext; 
                        //перевод в 10-ный и проверка наличи букв
                        yylval.Hex = buffer;
                        return HEX;
                    }  

[1-7][1-7]*         {
                        yylval.Dec = std::atoi(yytext);
                        return DEC;
                    }

[0][0-9]+           {
                        buffer = yytext;
                        //роверка наличия 8 или 8
                        yylval.Dec = buffer;
                        return DEC;
                    }        

[()=+-*/\[\],]      {
                        return *yytext;
                    }


"TRUE"|"true"          {
                            yylval.iBool = "true";
                            return BOOL;
                        }

"FALSE"|"false"         {
                            yylval.iBool = "false";
                            return BOOL;
                        }

"VAR"           return VAR;
"LOGITIZE"      return LOGITIZE;
"DIGITIZE"      return DIGITIZE;
"SIZE"          return SIZE;
"REDUCE"        return REDUCE;
"EXTENED"       return EXTENED;
"NOT"           return NOT;
"AND"           return AND;
"MXTRUE"        return MXTRUE;
"MXFALSE"       return MXFALSE;
"FOR"           return FOR;
"BOUNDARY"      return BOUNDARY;
"STEP"          return STEP;
"SWITCH"        return SWITCH;
"DO"            return DO;
"GET"           return GET;
"TASK"          return TASK;
"ROTATE RIGHT"  return R_RIGHT;
"ROTATE LEFT"   return R_LEFT;
"GET ENVIRONMENT"   return GET_E;
"MOVE"          return MOVE;
"FINDEXIT"      return FINDEXIT;
"RESULT"        return RESULT;
[\n]            return ENDLINE;


"MXEQ"|"MXLT"|"MXGT"|"MXLTE"|"MXGTE"        return MXCOMP;
"ELEQ"|"ELLT"|"ELGT"|"ELLTE"|"ELGTE"        return ELCOMP;



[ \t]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
