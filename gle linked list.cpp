#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->next = head;
    head = p;
}

void insertEnd(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;

    if (head == NULL) {
        head = p;
        return;
    }

    struct Node *t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = p;
}

void insertPosition(int x, int pos) {
    if (pos <= 1) {
        insertBeginning(x);
        return;
    }

    struct Node *t = head;
    for (int i = 1; t != NULL && i < pos - 1; i++)
        t = t->next;

    if (t == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->next = t->next;
    t->next = p;
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *t = head;
    head = head->next;
    free(t);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *t = head;
    while (t->next->next != NULL)
        t = t->next;

    free(t->next);
    t->next = NULL;
}

void deletePosition(int pos) {
    if (pos <= 1) {
        deleteBeginning();
        return;
    }

    struct Node *t = head;
    for (int i = 1; t != NULL && i < pos - 1; i++)
        t = t->next;

    if (t == NULL || t->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *p = t->next;
    t->next = p->next;
    free(p);
}

void display() {
    struct Node *t = head;

    if (t == NULL) {
        printf("List is empty\n");
        return;
    }

    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, x, pos;

    do {
        printf("\n1.Insert Beginning 2.Insert End 3.Insert Position");
        printf("\n4.Delete Beginning 5.Delete End 6.Delete Position");
        printf("\n7.Display 0.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &x);
                insertBeginning(x);
                break;
            case 2:
                scanf("%d", &x);
                insertEnd(x);
                break;
            case 3:
                scanf("%d%d", &x, &pos);
                insertPosition(x, pos);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                scanf("%d", &pos);
                deletePosition(pos);
                break;
            case 7:
                display();
                break;
        }
    } while (choice != 0);

    return 0;
}
