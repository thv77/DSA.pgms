#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

static Node *head = NULL;

static Node *create_node(int value)
{
    Node *node = malloc(sizeof *node);

    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    node->data = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

static void insert_front(int value)
{
    Node *node = create_node(value);

    if (node == NULL)
        return;

    node->next = head;
    if (head != NULL)
        head->prev = node;
    head = node;
}

static void insert_end(int value)
{
    Node *node = create_node(value);
    Node *current;

    if (node == NULL)
        return;

    if (head == NULL) {
        head = node;
        return;
    }

    current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = node;
    node->prev = current;
}

static void delete_value(int value)
{
    Node *current = head;

    while (current != NULL && current->data != value)
        current = current->next;

    if (current == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    printf("Deleted %d.\n", value);
}

static void display_forward(void)
{
    Node *current = head;

    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

static void display_reverse(void)
{
    Node *current = head;

    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (current->next != NULL)
        current = current->next;

    printf("Reverse: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

static void free_list(void)
{
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void)
{
    int choice, value;

    do {
        printf("\n1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete a value\n");
        printf("4. Display forward\n");
        printf("5. Display reverse\n");
        printf("0. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            free_list();
            return 1;
        }

        switch (choice) {
            case 1:
            case 2:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    free_list();
                    return 1;
                }
                if (choice == 1)
                    insert_front(value);
                else
                    insert_end(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1) {
                    free_list();
                    return 1;
                }
                delete_value(value);
                break;
            case 4:
                display_forward();
                break;
            case 5:
                display_reverse();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    free_list();
    return 0;
}
