#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

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
    struct Node *stack[MAX];
    int top = -1;
    struct Node *current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorder(struct Node *root) {
    if (root == NULL)
        return;

    struct Node *stack[MAX];
    int top = 0;
    stack[top] = root;

    while (top >= 0) {
        struct Node *current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;

        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

void postorder(struct Node *root) {
    if (root == NULL)
        return;

    struct Node *s1[MAX], *s2[MAX];
    int top1 = 0, top2 = -1;

    s1[top1] = root;

    while (top1 >= 0) {
        struct Node *current = s1[top1--];
        s2[++top2] = current;

        if (current->left != NULL)
            s1[++top1] = current->left;

        if (current->right != NULL)
            s1[++top1] = current->right;
    }

    while (top2 >= 0)
        printf("%d ", s2[top2--]->data);
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

    printf("Non-recursive Inorder: ");
    inorder(root);

    printf("\nNon-recursive Preorder: ");
    preorder(root);

    printf("\nNon-recursive Postorder: ");
    postorder(root);

    printf("\n");
    return 0;
}
