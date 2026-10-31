#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, int x) {
    if (root == NULL) {
        struct Node *p = malloc(sizeof(struct Node));
        p->data = x;
        p->left = p->right = NULL;
        return p;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct Node *root, int x) {
    while (root != NULL) {
        if (root->data == x)
            return 1;

        if (x < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

int main() {
    struct Node *root = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nEnter key to search: ");
    scanf("%d", &x);

    printf("%s\n", search(root, x) ? "Found" : "Not found");

    return 0;
}
