#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for student record
struct Student {
    char usn[20];
    char name[50];
    int semester;
};

// Function prototypes
void displayRecords(struct Student *records, int n);
void searchRecord(struct Student *records, int n, char *searchUSN);

int main() {
    int n;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array of structures
    struct Student *records = (struct Student *)malloc(n * sizeof(struct Student));

    // Input student records
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("USN: ");
        scanf("%s", records[i].usn);
        printf("Name: ");
        scanf("%s", records[i].name); // Assuming no spaces in name
        printf("Semester: ");
        scanf("%d", &records[i].semester);
    }

    // Display all records
    printf("\nStudent records:\n");
    displayRecords(records, n);

    // Search for a record
    char searchUSN[20];
    printf("\nEnter USN to search: ");
    scanf("%s", searchUSN);
    searchRecord(records, n, searchUSN);

    // Free the dynamically allocated memory
    free(records);
    return 0;
}

void displayRecords(struct Student *records, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("USN: %s\n", records[i].usn);
        printf("Name: %s\n", records[i].name);
        printf("Semester: %d\n", records[i].semester);
    }
}

void searchRecord(struct Student *records, int n, char *searchUSN) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(records[i].usn, searchUSN) == 0) {
            printf("\nRecord found:\n");
            printf("USN: %s\n", records[i].usn);
            printf("Name: %s\n", records[i].name);
            printf("Semester: %d\n", records[i].semester);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nRecord with USN %s not found\n", searchUSN);
    }
}
