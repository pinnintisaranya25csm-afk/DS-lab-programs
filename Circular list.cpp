#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

struct Node *createNode(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->prev = p->next = p;
    return p;
}

void insertBeginning(int x) {
    struct Node *p = createNode(x);

    if (head == NULL) {
        head = p;
        return;
    }

    struct Node *tail = head->prev;

    p->next = head;
    p->prev = tail;
    tail->next = p;
    head->prev = p;
    head = p;
}

void insertEnd(int x) {
    if (head == NULL) {
        head = createNode(x);
        return;
    }

    struct Node *p = createNode(x);
    struct Node *tail = head->prev;

    p->next = head;
    p->prev = tail;
    tail->next = p;
    head->prev = p;
}

void insertPosition(int x, int pos) {
    if (pos <= 1) {
        insertBeginning(x);
        return;
    }

    if (head == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *t = head;
    for (int i = 1; i < pos - 1 && t->next != head; i++)
        t = t->next;

    if (t->next == head && pos > 2) {
        printf("Invalid position\n");
        return;
    }

    struct Node *p = createNode(x);
    p->next = t->next;
    p->prev = t;
    t->next->prev = p;
    t->next = p;
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *t = head;

    if (head->next == head) {
        head = NULL;
    } else {
        struct Node *tail = head->prev;
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }

    free(t);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *tail = head->prev;

    if (tail == head) {
        head = NULL;
    } else {
        tail->prev->next = head;
        head->prev = tail->prev;
    }

    free(tail);
}

void deletePosition(int pos) {
    if (pos <= 1) {
        deleteBeginning();
        return;
    }

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *t = head;
    int i = 1;

    while (i < pos && t->next != head) {
        t = t->next;
        i++;
    }

    if (i != pos) {
        printf("Invalid position\n");
        return;
    }

    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void displayForward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *t = head;
    do {
        printf("%d <-> ", t->data);
        t = t->next;
    } while (t != head);

    printf("(head)\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *t = head->prev;
    struct Node *tail = t;

    do {
        printf("%d <-> ", t->data);
        t = t->prev;
    } while (t != tail);

    printf("(tail)\n");
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
