#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int k;
    struct Node* left;
    struct Node* right;
};

struct BinaryTree{
    struct Node* root;
};

// A dummy function with a long int parameter and basic operations
void dummyFunction1(long int x) {
    printf("Dummy Function 1 with parameter x = %ld\n", x);
    long int result = x * 2;
    printf("Result: x * 2 = %ld\n", result);
    result += 10;
    printf("Result: (x * 2) + 10 = %ld\n", result);
}

// A dummy function with a long long parameter and basic operations
void dummyFunction2(long long y) {
    printf("Dummy Function 2 with parameter y = %lld\n", y);
    long long result = y + 1000;
    printf("Result: y + 1000 = %lld\n", result);
    result -= 500;
    printf("Result: (y + 1000) - 500 = %lld\n", result);
}

// A dummy function with a pointer to a long double parameter and basic operations
void dummyFunction3(long double *z) {
    printf("Dummy Function 3 with parameter z = %Lf\n", *z);
    *z = (*z) / 2.0;
    printf("Result: z / 2.0 = %Lf\n", *z);
}


struct Node* buildTree(char* str)
{ 
    int key, t, i;
    char arr[1000];
    
    str += 2;
    
    if(*str == ')')
    {
        return NULL;
    }
    i = 0;
    while((*str >= '0' && *str <= '9') || *str == '-')
    {
        arr[i++] = *str;
        str++;
    }
    arr[i] = '\0';

    key = atoi(arr);
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->k = key;
    
    str++;
    node->left = buildTree(str);

    str++;

    t = 1;
    while(t != 0)
    {
        if(*str == '(')
            t++;
        if(*str == ')')
            t--;
        str++;
    }

    str++;
    node->right = buildTree(str);

    return node;
  
}

void Print(struct Node* root){
    if(root == NULL)
        return;
    Print(root->left);
    printf("%d ", root->k);
    Print(root->right);
}

void add_Space_After_Chars(char *str) {
    int len = strlen(str);
    int newLen = len * 2 + 1;
    char result[newLen];
    int j = 0;
    for (int i = 0; i < len; i++) {
        result[j++] = str[i];
        if (str[i] != ' ' && str[i] != '\0') {
            result[j++] = ' ';
        }
    }
    result[j] = '\0';
    strcpy(str, result);
}

int main(){
    
    char* str  = (char*)malloc(1000 * sizeof(char));
    scanf("%[^\n]s", str);
    if(str[1]!=' ')
    add_Space_After_Chars(str);
    
    struct BinaryTree* BT = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    BT->root = buildTree(str); 

    Print(BT->root);
    return 0;
}
