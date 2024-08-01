#include <stdio.h>
#include <stdlib.h>

// Structure used to define the nodes of a binary tree
struct node {
    int data;
    struct node *llink, *rlink;
} *root = NULL, *temp, *cur, *ptr;

void insert();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);

int main() {
    int ch;
    while (1) {
        printf("\nMENU:\n1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("\nInorder traversal:\n");
                    inorder(root);
                }
                break;
            case 3:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("\nPreorder traversal:\n");
                    preorder(root);
                }
                break;
            case 4:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("\nPostorder traversal:\n");
                    postorder(root);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Used to insert elements into the tree following the rules of construction of a binary search tree
void insert() {
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL) {
        root = temp;
    } else {
        ptr = root;
        while (ptr != NULL) {
            cur = ptr;
            if (temp->data > cur->data)
                ptr = ptr->rlink;
            else
                ptr = ptr->llink;
        }
        if (temp->data > cur->data)
            cur->rlink = temp;
        else
            cur->llink = temp;
    }
}

// Preorder traversal -> root, left, right
void preorder(struct node *root) {
    if (root == NULL) return;
    printf("%d\t", root->data);
    preorder(root->llink);
    preorder(root->rlink);
}

// Inorder traversal -> left, root, right
void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->llink);
    printf("%d\t", root->data);
    inorder(root->rlink);
}

// Postorder traversal -> left, right, root
void postorder(struct node *root) {
    if (root == NULL) return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t", root->data);
}
