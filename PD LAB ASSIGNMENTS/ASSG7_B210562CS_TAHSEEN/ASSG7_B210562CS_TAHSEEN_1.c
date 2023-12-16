// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>


// // Function to check if the given character is an operator
 
// struct Stack {
//     char items[100000];
//     int top;
// };

// void initialize(struct Stack *stack) {
//     stack->top = -1;
// }

// void Infx_POST_FX(char *INFX, char *POSTFX);

// int Is_Op(char ch);  

// // Function to get the precedence of an operator

// int MY_OPERATOR(int op){
//  if (op == '+' || op == '-')
//         return 1;
//     if (op == '*' || op == '/')
//         return 2;
//     return 0;
// }

// int Find_Precednc(char op) {
//    MY_OPERATOR(op);
// }


// int main() {
//     char INFX[100000];
//     char POSTFX[100000];

//     int n;
//     //printf("Enter the number of characters in the INFX expression: ");
//     scanf("%d", &n);
//     //printf("Enter the INFX expression in uppercase letters: ");
//     scanf(" %[^\n]", INFX);

//     Infx_POST_FX(INFX, POSTFX);

//     printf("%s ", POSTFX);

//     return 0;
// }

// int Is_Op(char ch) {
//     return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
// }

// // Function to convert INFX expression to POST_FX expression
// void Infx_POST_FX(char *INFX, char *POST_FX) {
//     int stack[100000];
//     int top = -1;
//     int i, j;

//     for (i = 0, j = 0; INFX[i]; i++) {
//         char ch = INFX[i];

//         if (ch == ' ' || ch == '\t') {
//             continue; // Ignore spaces and tabs
//         }

//         if (isalnum(ch)) {
//             POST_FX[j++] = ch; // If it's an operand, add it to the POST_FX expression
//         } else if (ch == '(') {
//             stack[++top] = ch; // If it's an opening parenthesis, push it onto the stack
//         } else if (ch == ')') {
//             while (top != -1 && stack[top] != '(') {
//                 POST_FX[j++] = stack[top--]; // Pop operators from the stack until an opening parenthesis is encountered
//             }
//             if (top != -1 && stack[top] == '(') {
//                 top--; // Pop the opening parenthesis from the stack
//             }
//         } else if (Is_Op(ch)) {
//             while (top != -1 && stack[top] != '(' && Find_Precednc(stack[top]) >= Find_Precednc(ch)) {
//                 POST_FX[j++] = stack[top--]; // Pop operators from the stack with higher or equal precedence
//             }
//             stack[++top] = ch; // Push the current operator onto the stack
//         }
//     }

//     while (top != -1) {
//         POST_FX[j++] = stack[top--]; // Pop any remaining operators from the stack
//     }

//     POST_FX[j] = '\0'; // Null-terminate the POST_FX expression
// }


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#define MAX_SIZE 100

struct Stack {
    char items[100000];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, char item) {
    if (stack->top >= 100000 - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void INFXToPOST_FX(const char *INFX, char *POST_FX) {
    struct Stack operatorStack;
    initialize(&operatorStack);

    int POST_FXIndex = 0;
    for (int i = 0; INFX[i]; i++) {
        char token = INFX[i];
        if (token == ' ') {
            continue; // Ignore spaces
        }

        if (isOperator(token)) {
            while (!isEmpty(&operatorStack) && precedence(operatorStack.items[operatorStack.top]) >= precedence(token)) {
                POST_FX[POST_FXIndex++] = pop(&operatorStack);
                POST_FX[POST_FXIndex++] = ' ';
            }
            push(&operatorStack, token);
        } else if (token == '(') {
            push(&operatorStack, token);
        } else if (token == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != '(') {
                POST_FX[POST_FXIndex++] = pop(&operatorStack);
                POST_FX[POST_FXIndex++] = ' ';
            }
            pop(&operatorStack); // Pop the '('
        } else {
            while (INFX[i] && INFX[i] != ' ' && !isOperator(INFX[i]) && INFX[i] != '(' && INFX[i] != ')') {
                POST_FX[POST_FXIndex++] = INFX[i++];
            }
            POST_FX[POST_FXIndex++] = ' ';
            i--; // Correct the position after the while loop
        }
    }

    while (!isEmpty(&operatorStack)) {
        POST_FX[POST_FXIndex++] = pop(&operatorStack);
        POST_FX[POST_FXIndex++] = ' ';
    }

    POST_FX[POST_FXIndex] = '\0';
}

int main() {
    int lenght;
    scanf("%d\n", &lenght);

    char INFXExpression[100000];
    char POST_FXExpression[100000];

    fgets(INFXExpression, 100000, stdin);
    INFXExpression[strlen(INFXExpression) - 1] = '\0'; // Remove the newline character

    INFXToPOST_FX(INFXExpression, POST_FXExpression);

    printf("%s ", POST_FXExpression);

    return 0;
}
