%{
	int COMMENT=0;
%}
identifier [a-zA-Z_][a-zA-Z0-9]*  
%% 
"/*" {COMMENT = 1;}{printf("%s is a comment\n", yytext);}
#.* {printf("%s is a preprocessor\n", yytext);}
int |
float |
double |
char |
short |
long |
if |
else |
for |
while |
do |
goto {if(!COMMENT)printf("%s is a keyword\n", yytext);}

{identifier}\( {if(!COMMENT) printf("%s is a function\n", yytext);}
\{ {if(!COMMENT) printf("BLOCK BEGINS\n");}
\} {if(!COMMENT) printf("BLOCK ENDS\n");}
{identifier} {if(!COMMENT) printf("%s is an IDENTIFIER\n", yytext);}
[0-9]+ {if(!COMMENT) printf("%s is a Number\n", yytext);}
\".*\" {if(!COMMENT) printf("%s is a String\n", yytext);}
\) {if(!COMMENT) printf("\n");}
= {if(!COMMENT)printf("\n %s is an ASSIGNMENT OPERATOR",yytext);}
\+ |
\- |
\/ |
\* |
% {if(!COMMENT) printf("\n%s is an OPERATOR",yytext);}
%% 
int main(){
	FILE *file = fopen("input.txt", "r");
	yyin = file;
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}