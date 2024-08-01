#include <stdio.h>
#include <math.h>

// Recursive function used to solve the Tower of Hanoi problem, it prints the order of movement of the disks
void tower(int n, char a, char b, char c) {
    if (n == 1) {
        printf("Move disk from %c to %c\n", a, c);
        return;
    }
    tower(n - 1, a, c, b);
    printf("Move disk from %c to %c\n", a, c);
    tower(n - 1, b, a, c);
}

// Main method
int main() {
    int n;
    printf("Enter number of disks\n");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'C');
    int x = pow(2, n) - 1;
    printf("Number of moves = %d\n", x);
    return 0;
}
