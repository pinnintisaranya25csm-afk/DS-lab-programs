#include <stdio.h>
#define MAX 100

struct Item {
    int data;
    int priority;
};

struct Item queue[MAX];
int n = 0;

void insert(int x, int p) {
    if (n == MAX) {
        printf("Priority queue is full\n");
        return;
    }

    int i = n - 1;

    while (i >= 0 && queue[i].priority > p) {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1].data = x;
    queue[i + 1].priority = p;
    n++;
}

void deleteHighestPriority() {
    if (n == 0) {
        printf("Priority queue is empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[0].data);

    for (int i = 1; i < n; i++)
        queue[i - 1] = queue[i];

    n--;
}

void display() {
    for (int i = 0; i < n; i++)
        printf("%d (Priority %d)\n",
               queue[i].data, queue[i].priority);
}

int main() {
    int choice, x, p;

    do {
        printf("\n1.Insert 2.Delete 3.Display 0.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d%d", &x, &p);
                insert(x, p);
                break;
            case 2:
                deleteHighestPriority();
                break;
            case 3:
                display();
                break;
        }
    } while (choice != 0);

    return 0;
}
