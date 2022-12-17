%{
    #include <stdio.h>
%}

%%
[0-9]{5}[ -][0-9]{7}[ -][0-9] {printf("\nValid ID. Number is: %s\n", yytext);}
.* {printf("\nInvalid ID. Number is: %s\n", yytext);}
%%

void main() {
 yylex();
}
