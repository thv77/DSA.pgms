#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int value)
{
    if (root == NULL) {
        Node *node = malloc(sizeof *node);
        if (node == NULL) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        node->data = value;
        node->left = node->right = NULL;
        return node;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate value %d ignored\n", value);

    return root;
}

void inorder(const Node *root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

Node *search(Node *root, int key)
{
    while (root != NULL && root->data != key)
        root = (key < root->data) ? root->left : root->right;
    return root;
}

void free_tree(Node *root)
{
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main(void)
{
    Node *root = NULL;
    int n, i, value, key;

    printf("Number of values to insert (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        printf("Invalid number of values.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Value %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            free_tree(root);
            return 1;
        }
        root = insert(root, value);
    }

    printf("Binary search tree (inorder): ");
    inorder(root);
    printf("\nEnter value to search: ");
    if (scanf("%d", &key) != 1) {
        free_tree(root);
        return 1;
    }

    if (search(root, key) != NULL)
        printf("%d is present in the tree.\n", key);
    else
        printf("%d is not present in the tree.\n", key);

    free_tree(root);
    return 0;
}
