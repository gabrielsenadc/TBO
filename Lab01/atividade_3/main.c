#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int operation(int n1, char op, int n2){
    if(op == '+') return n1 + n2;
    if(op == '*') return n1 * n2;
    if(op == '/') return n1 / n2;
    if(op == '-') return n1 - n2;

    return 0;
}

int concatena(int n1, int n2){
    return (10 * n1) + n2;
}

int main(){
    stackType * numStack = createStack();
    stackType * opStack = createStack();

    char c;
    int flag = 0;
    int nOpen = 0, nClosed = 0;
    while(scanf("%c", &c) == 1){
        if(c == '(') nOpen++;
        if(c == ')') nClosed++;
        
        if(c <= '9' && c >= '0'){
            double * num = malloc(sizeof(double));
            *num = c - '0';
            
            if(flag){
                double * n1 = pop(numStack);
                *num = concatena(*n1, *num);

                free(n1);
            }
            
            push(numStack, num);

            flag = 1;
        } else flag = 0;
        if(c == '+' || c == '*' || c == '/' || c == '-'){
            char * op = malloc(sizeof(char));
            *op = c;
            push(opStack, op);
        }
        if(c == ')'){
            double * num1 = pop(numStack);
            double * num2 = pop(numStack);

            char * op = pop(opStack);

            double * num = malloc(sizeof(double));
            *num = operation(*num2, *op, *num1);

            push(numStack, num);

            free(num1);
            free(num2);
            free(op);
        }
        if(nOpen == nClosed) break;
    }

    double * num = pop(numStack);

    printf("%.0lf\n", *num);

    free(num);
    freeStack(numStack);
    freeStack(opStack);

    return 0;
}