#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insertBeginning(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->prev = NULL;
    p->next = head;

    if (head != NULL)
        head->prev = p;

    head = p;
}

void insertEnd(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;

    if (head == NULL) {
        p->prev = NULL;
        head = p;
        return;
    }

    struct Node *t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = p;
    p->prev = t;
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
    p->prev = t;
    p->next = t->next;

    if (t->next != NULL)
        t->next->prev = p;

    t->next = p;
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *t = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(t);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *t = head;
    while (t->next != NULL)
        t = t->next;

    if (t->prev != NULL)
        t->prev->next = NULL;
    else
        head = NULL;

    free(t);
}

void deletePosition(int pos) {
    if (pos <= 1) {
        deleteBeginning();
        return;
    }

    struct Node *t = head;
    for (int i = 1; t != NULL && i < pos; i++)
        t = t->next;

    if (t == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (t->prev != NULL)
        t->prev->next = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;

    free(t);
}

void displayForward() {
    struct Node *t = head;

    while (t != NULL) {
        printf("%d <-> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *t = head;
    while (t->next != NULL)
        t = t->next;

    while (t != NULL) {
        printf("%d <-> ", t->data);
        t = t->prev;
    }
    printf("NULL\n");
}

int main() {
    int choice, x, pos;

    do {
        printf("\n1.Insert Beginning 2.Insert End 3.Insert Position");
        printf("\n4.Delete Beginning 5.Delete End 6.Delete Position");
        printf("\n7.Forward 8.Backward 0.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: scanf("%d", &x); insertBeginning(x); break;
            case 2: scanf("%d", &x); insertEnd(x); break;
            case 3: scanf("%d%d", &x, &pos); insertPosition(x, pos); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: scanf("%d", &pos); deletePosition(pos); break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
        }
    } while (choice != 0);

    return 0;
}
