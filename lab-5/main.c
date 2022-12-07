#include <stdio.h>
#include <stdlib.h>
#include "string.h"

# define MAX_CHARS 5000


void write_line_no(int line_no) {
    char str[256];
    sprintf(str, "%d. ", line_no);
    fputs(str, stdout);
}

void add_line_number (FILE *read_file) {
    int i = 1;
    write_line_no( i);
    int c;
    while ( (c = getc(read_file)) != EOF) {
        putc(c, stdout);
        if (c == '\n') {
            i++;
            write_line_no(i);
        }
    }
}

void id_macros(FILE *read_file) {
    char str[MAX_CHARS];
    char copy[MAX_CHARS];
    int no_of_macros = 0;

    while ( (fgets(str, MAX_CHARS, read_file))) {

        for (int i=0; i < strlen(str); i++) {
            switch (str[i]) {
                case ('#'): {
                    for (int j=i; j < strlen(str); j++) {
                        switch (str[j]) {
                            case ('d'): {
                                if (str[j+1] == 'e' && str[j+2] == 'f' && str[j+3] == 'i') {
                                    no_of_macros++;
                                    strcat(copy, str);
                                }
                            }
                        }
                    }
                }
                default: {
                    continue;
                }
            }
        }
    }
    printf("\n%d macros found in the file:\n\n", no_of_macros);
    printf("%s\n", copy + 1);
}



int main(int argc, char *argv[]) {
    printf("\n__________________________________________\n\n"
           "             Abdullah Baig          \n"
           "             Ismail Sajid          "
           "\n__________________________________________\n\n");
    if (argc == 2) {
        FILE *in_file = fopen(argv[1], "r");

        if (in_file == NULL) {
            printf("Error opening file!");
            exit(-1);
        }

        printf("\n_____________________\n\nFile with Line Number: \n_____________________\n\n");
        add_line_number(in_file);
        printf("\n");
        in_file = fopen(argv[1], "r");
        id_macros(in_file);
    } else {
        printf("\nIncorrect number of arguments\n");
        exit(0);
    }
}