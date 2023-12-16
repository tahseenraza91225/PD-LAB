#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
}*root=NULL;

struct Node* create_Node(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->key = k;
    temp->left = temp->right = temp->parent = NULL;
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

struct Node* search(struct Node* root, int key) {
    if (root == NULL)return NULL; 
    if( root->key == key) {
        return root;
    }

    if (key > root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
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

int successor(struct Node* root, int key) {
    struct Node* curr = search(root, key);
    if (curr == NULL) {
        return -1;
    }

    if (curr->right != NULL) {
        return find_Min(curr->right);
    }

    struct Node* succ = NULL;
    while (root != NULL) {
        if (key > root->key) {
            succ = root;
            root = root->left;
        } else if (key < root->key) {
            root = root->right;
        } else {
            break;
        }
    }

    if (succ!= NULL) {
        return succ->key;
    } else {
        return -1;
    }
}

int predecessor(struct Node* root, int key) {
    struct Node* curr= search(root, key);
    if (curr == NULL) {
        return -1;
    }

    if (curr->left != NULL) {
        return find_Max(curr->left);
    }
    
    struct Node* pre = NULL;
    while (root != NULL) {
        if (key < root->key) {
            pre = root;
            root = root->right;
        } else if (key > root->key) {
            root = root->left;
        } else {
            break;
        }
    }

    if (pre != NULL) {
        return pre->key;
    } else {
        return -1;
    }
}

struct Node* Delete(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key > root->key) {
        root->left = Delete(root->left, key);
    } else if (key < root->key) {
        root->right = Delete(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        root->key = find_Min(root->right);
        root->right = Delete(root->right, root->key);
    }

    return root;
}

int main() {
    char c;
    int key;

    while (1) {
        scanf(" %c", &c);
        

        switch (c) {
            case 'a':
                scanf("%d", &key);
                root = Insert(root, key);
                break;
            case 'd':
                scanf("%d", &key);
                if (search(root, key)) {
                    root = Delete(root, key);
                    printf("%d\n", key);
                } else {
                    printf("-1\n");
                }
                break;
            case 'c':
                scanf("%d", &key);
                int succ = successor(root, key);
                if (succ != -1) {
                    printf("%d\n", succ);
                } else {
                    printf("-1\n");
                }
                break;
            case 'r':
                scanf("%d", &key);
                int pre = predecessor(root, key);
                if (pre != -1) {
                    printf("%d\n", pre);
                } else {
                    printf("-1\n");
                }
                break;
            case 'p':
                if (root) {
                    preorder(root);
                    printf("\n");
                } else {
                    printf("-1\n");
                }
                break;
            default:
                exit(1);
        }
    }
    
    // freeTree(root);
    return 0;
}
