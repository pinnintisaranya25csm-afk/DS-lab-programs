#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x) {
    struct Node *p = malloc(sizeof(struct Node));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    p->data = x;
    p->next = top;
    top = p;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node *t = top;
    printf("Popped: %d\n", t->data);
    top = top->next;
    free(t);
}

void peek() {
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", top->data);
}

void display() {
    struct Node *t = top;

    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }

    printf("\n");
}

int main() {
    int choice, x;

    do {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 0.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: scanf("%d", &x); push(x); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    } while (choice != 0);

    return 0;
}
