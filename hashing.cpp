#include <stdio.h>
#define SIZE 10

int table[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hash(int key) {
    return (key % SIZE + SIZE) % SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void insert(int key, int method) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int index;

        if (method == 1)
            index = (h + i) % SIZE;
        else if (method == 2)
            index = (h + i * i) % SIZE;
        else
            index = (h + i * hash2(key)) % SIZE;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }

    printf("No empty slot found\n");
}

int search(int key, int method) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int index;

        if (method == 1)
            index = (h + i) % SIZE;
        else if (method == 2)
            index = (h + i * i) % SIZE;
        else
            index = (h + i * hash2(key)) % SIZE;

        if (table[index] == -1)
            return -1;

        if (table[index] == key)
            return index;
    }

    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("Index %d: %d\n", i, table[i]);
}

int main() {
    int choice, key, method;

    initialize();

    printf("1.Linear Probing 2.Quadratic Probing 3.Double Hashing\n");
    printf("Choose collision resolution method: ");
    scanf("%d", &method);

    do {
        printf("\n1.Insert 2.Search 3.Display 0.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &key);
                insert(key, method);
                break;
            case 2:
                scanf("%d", &key);
                {
                    int index = search(key, method);
                    if (index == -1)
                        printf("Key not found\n");
                    else
                        printf("Key found at index %d\n", index);
                }
                break;
            case 3:
                display();
                break;
        }
    } while (choice != 0);

    return 0;
}
