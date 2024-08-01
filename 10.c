#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int a[MAX], count = 0;

// Used to display the hash table
void display() {
    printf("Hash table contents:\n");
    for (int i = 0; i < MAX; i++) {
        if (a[i] != -1)
            printf("\n%d %d", i, a[i]);
        else
            printf("\n%d -1", i);
    }
    printf("\n");
}

// Used to insert elements into the hash table
void insert() {
    int num, key;
    printf("Enter the number: ");
    scanf("%d", &num);
    key = num % MAX;

    if (a[key] == -1) {
        a[key] = num;
        count++;
    } else {
        printf("Collision detected\n");
        if (count == MAX) {
            printf("Hash table is full\n");
            exit(0);
        }
        printf("Collision handled using linear probing method\n");
        for (int i = key + 1; i < MAX; i++) {
            if (a[i] == -1) {
                a[i] = num;
                count++;
                return;
            }
        }
        for (int i = 0; i < key; i++) {
            if (a[i] == -1) {
                a[i] = num;
                count++;
                return;
            }
        }
    }
}

// Main method
int main() {
    int ch;

    for (int i = 0; i < MAX; i++) {
        a[i] = -1;
    }

    while (1) {
        printf("\nPress 1. Insert 2. Display 3. EXIT\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
