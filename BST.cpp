#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

struct Node *insert(struct Node *root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

struct Node *search(struct Node *root, int x) {
    while (root != NULL && root->data != x) {
        if (x < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return root;
}

struct Node *minimum(struct Node *root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node *deleteNode(struct Node *root, int x) {
    if (root == NULL)
        return NULL;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) {
            struct Node *t = root->right;
            free(root);
            return t;
        }

        if (root->right == NULL) {
            struct Node *t = root->left;
            free(root);
            return t;
        }

        struct Node *t = minimum(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, x;

    do {
        printf("\n1.Insert 2.Delete 3.Search 4.Inorder 0.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 2:
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;
            case 3:
                scanf("%d", &x);
                printf("%s\n", search(root, x) ? "Found" : "Not found");
                break;
            case 4:
                inorder(root);
                printf("\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
