#include <stdio.h>
#include <stdlib.h>

// Structure to describe each node in a doubly linked list
struct node {
    int info;
    struct node *prev, *next;
};

struct node* start = NULL;

// Function to traverse the list and print out the elements present in the list
void traverse() {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp = start;
    while (temp != NULL) {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
}

// Function to insert a new node at the beginning of the list and is used to create the DLL
void insertAtFront() {
    int data;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->prev = NULL;
    temp->next = start;
    if (start != NULL) {
        start->prev = temp;
    }
    start = temp;
}

/* Function to insert a new node to the left of the value specified,
   but for the function to work without error the element entered must be present in the list.
   to make it insert only if the element is present and display element not found if not present
   we can use the findEle() function to check if the element is present */
void insertAtPosition() {
    int data, ele;
    struct node *temp, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("\nEnter key value of node: ");
    scanf("%d", &ele);
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->info = data;

    temp = start;
    while (temp != NULL && temp->info != ele) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

// Used to find the position of the element in the list if present it returns position value if not it returns -1
int findEle() {
    int ele;
    printf("\nEnter element to be deleted: ");
    scanf("%d", &ele);
    int i = 1;
    struct node* temp = start;
    while (temp != NULL) {
        if (temp->info == ele) {
            return i;
        }
        i++;
        temp = temp->next;
    }
    return -1;
}

// Function to delete an element in the list based on its key value, the position is given from the findEle() function
void deletePosition(int pos) {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *temp = start;
    if (pos == 1) {
        start = temp->next;
        if (start != NULL) {
            start->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nPosition does not exist\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

// Main method to control the program
int main() {
    int choice, n, pos;
    while (1) {
        printf("\n\t1 To see list\n");
        printf("\t2 Create a list\n");
        printf("\t3 For insertion to the left of key value\n");
        printf("\t4 For deletion of element\n");
        printf("\t5 To exit\n");
        printf("\nEnter Choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    insertAtFront();
                }
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                pos = findEle();
                if (pos == -1) {
                    printf("Element not found\n");
                } else {
                    deletePosition(pos);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Incorrect Choice. Try Again\n");
                break;
        }
    }
    return 0;
}
