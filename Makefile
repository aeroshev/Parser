all:
	flex lexer.l
	bison -d -v parser.y
	g++ -Wno-deprecated-register -std=c++14 lex.yy.c parser.tab.c -O2 -Wall -o lab.out

	