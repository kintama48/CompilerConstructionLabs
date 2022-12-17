%{
    #include <stdio.h>
%}

%%
(0|1)*(00)(0|1)* {printf("\nValid String\n");}
.* {printf("\nInvalid String\n"); }
%%

void main() {
 yylex();
}
