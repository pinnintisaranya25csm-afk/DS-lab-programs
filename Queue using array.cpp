#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        printf("Queue is full\n");
    else
        queue[++rear] = x;
}

void dequeue() {
    if (front > rear)
        printf("Queue is empty\n");
    else
        printf("Deleted: %d\n", queue[front++]);
}

void display() {
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

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
