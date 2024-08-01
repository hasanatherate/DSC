#include <stdio.h>

// Function implementing binary search
int binary_search(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Main method
int main() {
    int arr[20];
    int target, i, n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements in ascending order\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be found\n");
    scanf("%d", &target);

    int result = binary_search(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
