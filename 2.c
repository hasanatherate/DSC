#include <stdio.h>
#include <stdlib.h>

// Define maximum size of the stack
#define MAX 10

// Stack variables
int stack[MAX], top = -1, n, x, i;

// Function prototypes
void push();
void pop();
void display();

int main() {
    int choice;
    printf("Enter the size of STACK [max %d]: ", MAX);
    scanf("%d", &n);
    
    if (n > MAX) {
        printf("Stack size exceeds maximum limit of %d\n", MAX);
        return 1;
    }

    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t------------------------------");
    
    do {
        printf("\n\nChoose one from the below options...\n");
        printf("\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t Exiting...");
                break;
            default:
                printf("\n\t Please Enter a Valid Choice (1/2/3/4)");
        }
    } while (choice != 4);

    return 0;
}

void push() {
    if (top >= n - 1) {
        printf("\n\tSTACK is overflow");
    } else {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top <= -1) {
        printf("\n\tStack is underflow");
    } else {
        printf("\n\tThe popped element is %d", stack[top]);
        top--;
    }
}

void display() {
    if (top >= 0) {
        printf("\nThe elements in STACK\n");
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
        printf("\nPress Next Choice");
    } else {
        printf("\nThe STACK is empty");
    }
}
