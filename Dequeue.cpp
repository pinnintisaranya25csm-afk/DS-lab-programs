#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX - 1) ||
           (front == rear + 1);
}

void insertFront(int x) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        front = (front - 1 + MAX) % MAX;

    deque[front] = x;
}

void insertRear(int x) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    deque[rear] = x;
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + MAX) % MAX;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;

    while (1) {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice, x;

    do {
        printf("\n1.Insert Front 2.Insert Rear");
        printf("\n3.Delete Front 4.Delete Rear");
        printf("\n5.Display 0.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: scanf("%d", &x); insertFront(x); break;
            case 2: scanf("%d", &x); insertRear(x); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
        }
    } while (choice != 0);

    return 0;
}
