#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void peek() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

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
