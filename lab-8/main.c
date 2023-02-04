#include <stdio.h>
#include "string.h"

int S();
int X();
int Z();

char expr[100];
int count, l;

int main() {
    count = 0;
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\nS -> rXd | rZd\nX -> oa | ea\nZ -> ai\n");
    printf("\nEnter the string to be checked: ");
    fgets(expr, 100, stdin);
    expr[strlen(expr) - 1] = '$';

    if (S()) {
        if (expr[count] == '$') {
            printf("\nString is accepted\n");
        }
        else {
            printf("\nString is not accepted\n");
        }
    } else {
        printf("\nString not accepted\n");
    }
    return 0;
}

int S() {
    if (expr[count] == 'r') {
        count++;
        if (X()) {
            if (expr[count] == 'd') {
                count++;
                return 1;
            } else {
                return 0;
            }
        } else if (Z()) {
            if (expr[count] == 'd') {
                count++;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int X() {
    if (expr[count] == 'o') {
        count++;
        if (expr[count] == 'a') {
            count++;
            return 1;
        } else {
            return 0;
        }
    } else if (expr[count] == 'e') {
        count++;
        if (expr[count] == 'a') {
            count++;
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int Z() {
    if (expr[count] == 'a') {
        count++;
        if (expr[count] == 'i') {
            count++;
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
