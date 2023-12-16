#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    struct node *rt, *lt, *prev;
    char data;
} *cur, *p, *root = NULL;
char st[1000];
int top = -1;

void push(char el)
{
    top++;
  st[top] = el; 
}

char pop()
{
  return st[top];
  top--;
}

int isoperator(char val)
{

    if (val == '+' || val == '-' || val == '*' || val == '/' || val == '%')
        return 1;
    else return 0;

}
void print(struct node *root);
struct node*  create(int x){
    struct node* t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->lt = NULL;
    t->rt = NULL;
    t->prev = NULL;
    return t;
}
int main() {
    char a[10000];
    int len, i;
    struct node *temp;

    scanf("%s", a);
    int n = strlen(a);
    for (i = n - 1; i >= 0; i--) {
        temp=create(a[i]);
        if (root == NULL) {
            root = temp;
            cur = p = root;
        } else {
            if (isoperator(a[i])) {
                if (p->rt == NULL) {
                    cur = temp;
                    p->rt = cur;
                    cur->prev = p;
                    p = cur;
                } else if (p->lt == NULL) {
                    cur = temp;
                    p->lt = cur;
                    cur->prev = p;
                    p = cur;
                } else {
                    while (p->lt != NULL) {
                        p = p->prev;
                    }
                    cur = temp;
                    p->lt = cur;
                    cur->prev = p;
                    p = cur;
                }
            } 
            else {
                if (p->rt == NULL) {
                    cur = temp;
                    p->rt = cur;
                    cur->prev = p;
                } else if (p->lt == NULL) {
                    cur = temp;
                    p->lt = cur;
                    cur->prev = p;
                } else {
                    while (p->lt != NULL) {
                        p = p->prev;
                    }
                    cur = temp;
                    p->lt = cur;
                    cur->prev = p;
                    p = cur;
                }
            }
        }
    }
    print(root); 
    return 0;
}

void print(struct node *root) {
    if (root != NULL) {
        if ((root->lt != NULL || root->rt != NULL) && root->prev != NULL) {
            printf("(");
        }
        print(root->lt);
        printf("%c", root->data);
        print(root->rt);
        if ((root->lt != NULL || root->rt != NULL) && root->prev != NULL) {
            printf(")");
        }
    }
}
