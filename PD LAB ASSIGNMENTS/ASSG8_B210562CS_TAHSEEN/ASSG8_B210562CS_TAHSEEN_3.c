#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
}*root=NULL;

struct TreeNode* Create_Node(int k) {
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->key = k;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct TreeNode* Insert(struct TreeNode* root, int k) {
    if (root == NULL) {
        return Create_Node(k);
    }
    if (k < root->key) {
        root->left = Insert(root->left, k);
    } else if (k > root->key) {
        root->right = Insert(root->right, k);
    }
    return root;
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

struct TreeNode* Find_Min(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct TreeNode* Delete(struct TreeNode* root, int k) {
    if (root == NULL) {
        return root;
    }
    if (k < root->key) {
        root->left = Delete(root->left, k);
    } else if (k > root->key) {
        root->right = Delete(root->right, k);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = Find_Min(root->right);
        root->key = temp->key;
        root->right = Delete(root->right, temp->key);
    }
    return root;
}

void Prnt(struct TreeNode* root) {
    if (root == NULL) {
        printf("( )");
        return;
    }
    printf("( %d", root->key);
    Prnt(root->left);
    Prnt(root->right);
    printf(" )");
}

int main() {

    char c;
    int key;

    while (1) {
        scanf(" %c", &c);
        if (c == 'i') {
            scanf("%d", &key);
            root = Insert(root, key);
        } else if (c == 'd') {
            scanf("%d", &key);
            root = Delete(root, key);
        } else if (c == 'p') {
            Prnt(root);
            printf("\n");
        }else{
            exit(1);
        }
    }

    return 0;
}
