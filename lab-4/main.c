#include <stdio.h>
#include <stdlib.h>
#include "string.h"

# define MAX_CHARS 5000



int main() {
    printf("\n__________________________________________\n\n"
           "             Section - B\n"
           "      Abdullah Baig - 231485698\n"
           "             Ismail Sajid          "
           "\n__________________________________________\n\n");
    char str[MAX_CHARS];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int char_detected = 0;
    int no_of_spaces = 0;
    char str_copy[MAX_CHARS];
    int index = 0;
    int semi_colon_written = 0;

    for (int i=0; i < strlen(str); i++) {
        if (semi_colon_written) {
            str_copy[index] = '\n';
            index++;
            break;
        }
        switch (str[i]) {
            case (' '): {
                if (char_detected == 0) {
                    continue;
                } else if (no_of_spaces == 0) {
                    if (char_detected == 1) {
                        int temp_char_detected = 0;
                        for (int j = i; j < strlen(str); j++) {
                            if (str[j] != ' ' && str[j] != ';' && str[j] != '\n') {
                                temp_char_detected = 1;
                                break;
                            }
                        }
                        if (temp_char_detected == 0) {
                            str_copy[index] = ';';
                            index++;
                            semi_colon_written = 1;
                            continue;
                        }
                    }
                    str_copy[index] = str[i];
                    index++;
                    no_of_spaces++;
                    continue;
                } else if (no_of_spaces == 1) {
                    continue;
                }
            }
            default: {
                char_detected = 1;
                str_copy[index] = str[i];
                index++;
                no_of_spaces = 0;
            }
        }
    }
    printf("%s", str_copy);
    return 0;
}
