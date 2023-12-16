#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>

struct Stack{
    char items[100000];
    int top;
    unsigned capacity;
    int* array;
};

void Initialize(struct Stack *stack) {
    stack->top = -1;
}

struct Stack* Create_Stack( unsigned capacity ){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack) return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
 
    if (!stack->array) return NULL;
 
    return stack;
}

int isEmpty(struct Stack* stack);
int peek(struct Stack* stack);
 
 
void Push(struct Stack *stack, char item) {
    if (stack->top >= 100000 - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}

char Pop(struct Stack *stack);


int pop(struct Stack* stack){
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
 
void push(struct Stack* stack,int op){
    stack->array[++stack->top] = op;
}

int evaluatePostfix(char* exp){
    struct Stack* stack = Create_Stack(strlen(exp));
    int i;
    if (!stack) return -1;
    for (i = 0; exp[i]; ++i)
    {
        if(exp[i]==' ')continue;
        else if (isdigit(exp[i]))
        {
            int num=0;
            while(isdigit(exp[i]))
            {
            num=num*10 + (int)(exp[i]-'0');
                i++;
            }
            i--;
            push(stack,num);
        }
         
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
             
            switch (exp[i])
            {
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2/val1); break;
             
            }
        }
    }
    return pop(stack);
}
 
int main()
{
    char exp[100000];
    scanf(" %[^\n]",exp);
    printf ("%d", evaluatePostfix(exp));
    return 0;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1 ;
}
 
char Pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

int peek(struct Stack* stack){
    return stack->array[stack->top];
}
