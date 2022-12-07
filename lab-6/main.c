#include <stdio.h>
#include <stdlib.h>
#include "string.h"

# define MAX_CHARS 1024

int main(int argc, char *argv[]) {
    printf("\n__________________________________________\n\n"
           "             Abdullah Baig          \n"
           "               231485698          \n"
           "                Lab 6          \n"
           "\n__________________________________________\n\n");

    char str[MAX_CHARS];


    if (argc == 2) {

        FILE* read_file = fopen(argv[1], "r");
        while ((fgets(str, MAX_CHARS, read_file))) {
            if (strlen(str) <= 2) {
                puts("Invalid string length!\n");
                exit(0);
            }

            char* current_state = "q0";
            int current_index = 0;
            printf("Input string is: %s\nState transitions are shown below: \n", str);
            
            while (str[current_index] != '$') {
                goto q0;

                //
                q0:
                if (str[current_index] == 'a') {
                    puts("Received a on state q0 ----- Moving to state q1");
                    current_index++;
                    goto q1;
                } else if (str[current_index] == 'b') {
                    puts("Received b on state q0 ----- Moving to state q3");
                    current_index++;
                    goto q3;
                }  else if (str[current_index] == '$') {
                    goto string_rejected;
                } else {
                    current_state = "q0";
                    goto invalid_char;
                }

                //
                q1:
                if (str[current_index] == 'a') {
                    puts("Received a on state q1 ----- Moving to state q2");
                    current_index++;
                    goto q2;
                } else if (str[current_index] == 'b') {
                    puts("Received b on state q1 ----- Moving to state q3");
                    current_index++;
                    goto q3;
                }   else if (str[current_index] == '$') {
                    goto string_rejected;
                } else {
                    current_state = "q1";
                    goto invalid_char;
                }

                //
                q2:
                if (str[current_index] == 'a') {
                    puts("Received a on state q2 ----- Moving to state q2");
                    current_index++;
                    goto q2;
                } else if (str[current_index] == 'b') {
                    puts("Received b on state q2 ----- Moving to state q3");
                    current_index++;
                    goto q3;
                }  else if (str[current_index] == '$') {
                    goto string_accepted;
                } else {
                    current_state = "q2";
                    goto invalid_char;
                }

                //
                q3:
                if (str[current_index] == 'a') {
                    puts("Received a on state q3 ----- Moving to state q1");
                    current_index++;
                    goto q1;
                } else if (str[current_index] == 'b') {
                    puts("Received b on state q3 ----- Moving to state q4");
                    current_index++;
                    goto q4;
                }  else if (str[current_index] == '$') {
                    goto string_rejected;
                }else {
                    current_state = "q3";
                    goto invalid_char;
                }

                //
                q4:
                if (str[current_index] == 'a') {
                    puts("Received a on state q4 ----- Moving to state q1");
                    current_index++;
                    goto q1;
                } else if (str[current_index] == 'b') {
                    puts("Received b on state q4 ----- Moving to state q4");
                    current_index++;
                    goto q4;
                } else if (str[current_index] == '$') {
                    goto string_accepted;
                } else {
                    current_state = "q4";
                    goto invalid_char;
                }

                string_accepted:
                puts("End of String.\nString Accepted!\n");
                exit(0);

                string_rejected:
                puts("End of String.\nString Rejected!\n");
                exit(0);

                invalid_char:
                printf("Received unknown character %c on state: %s\nTerminating process...\n", str[current_index],
                       current_state);
                exit(0);
            }
        }
    } else {
        printf("\nInvalid arguments\n");
        exit(0);
    }
}
