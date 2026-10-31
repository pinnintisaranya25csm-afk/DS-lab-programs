#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *p = malloc(sizeof(struct Node));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    p->data = x;
    p->next = NULL;

    if (rear == NULL)
        front = rear = p;
    else {
        rear->next = p;
        rear = p;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *t = front;
    printf("Deleted: %d\n", t->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(t);
}

void display() {
    struct Node *t = front;

    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }

    printf("\n");
}

int main() {
    int choice, x;

    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: scanf("%d", &x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (choice != 0);

    return 0;
}
