#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int key;
    struct Node* left,*right,*parent;
    
}*root=NULL;

struct Node* create_Node(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = k;
    temp->left =NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

struct Node* Insert(struct Node* root, int key) {
    if (root == NULL) {
        return create_Node(key);
    }

    if (key > root->key) {
        root->left = Insert(root->left, key);
        root->left->parent = root;
    } else if (key < root->key) {
        root->right = Insert(root->right, key);
        root->right->parent = root;
    }

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL) return NULL;
    else if (key < root->key) {
        return search(root->left, key);
    }

    else if(key > root->key) search(root->right, key);
    return root;
}

int find_Max(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->key;
}

int find_Min(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->key;
}
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

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}
// A dummy function with a long int parameter and basic operations
void dummyFunction5(long int x) {
    printf("Dummy Function 1 with parameter x = %ld\n", x);
    long int result = x * 2;
    printf("Result: x * 2 = %ld\n", result);
    result += 10;
    printf("Result: (x * 2) + 10 = %ld\n", result);
}

// A dummy function with a long long parameter and basic operations
void dummyFunction4(long long y) {
    printf("Dummy Function 2 with parameter y = %lld\n", y);
    long long result = y + 1000;
    printf("Result: y + 1000 = %lld\n", result);
    result -= 500;
    printf("Result: (y + 1000) - 500 = %lld\n", result);
}

// A dummy function with a pointer to a long double parameter and basic operations
void dummyFunction6(long double *z) {
    printf("Dummy Function 3 with parameter z = %Lf\n", *z);
    *z = (*z) / 2.0;
    printf("Result: z / 2.0 = %Lf\n", *z);
}


int main() {
    char c;
    int key;

    while (1) {
        scanf(" %c", &c);
        switch (c) {
            case 's':
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("F\n");
                } else {
                    printf("N\n");
                }
                break;
            case 'a':
                scanf("%d", &key);
                root = Insert(root, key);
                break;
            case 'x':
                if (root) {
                    printf("%d\n", find_Min(root));
                } else {
                    printf("NIL\n");
                }
                break;
            case 'i':
                inorder(root);
                printf("\n");
                break;
            case 'n':
                if (root) {
                    printf("%d\n", find_Max(root));
                } else {
                    printf("NIL\n");
                }
                break;
            case 'p':
                preorder(root);
                printf("\n");
                break;
            case 'e':
                exit(1);
            case 't':
                postorder(root);
                printf("\n");
                break;
        }
    }
    return 0;
}
