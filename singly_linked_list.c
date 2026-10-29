#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
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
    node->next = NULL;
    return node;
}

static void insert_first(int value)
{
    Node *node = create_node(value);
    if (node == NULL) return;
    node->next = head;
    head = node;
}

static void insert_last(int value)
{
    Node *node = create_node(value);
    Node *p;
    if (node == NULL) return;
    if (head == NULL) {
        head = node;
        return;
    }
    p = head;
    while (p->next != NULL) p = p->next;
    p->next = node;
}

/* Insert value immediately after the first node containing key. */
static void insert_after(int key, int value)
{
    Node *p = head;
    Node *node;
    while (p != NULL && p->data != key) p = p->next;
    if (p == NULL) {
        printf("Key not found.\n");
        return;
    }
    node = create_node(value);
    if (node == NULL) return;
    node->next = p->next;
    p->next = node;
}

static void delete_first(void)
{
    Node *old;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    old = head;
    head = head->next;
    printf("Deleted: %d\n", old->data);
    free(old);
}

static void delete_last(void)
{
    Node *p, *previous = NULL;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    p = head;
    while (p->next != NULL) {
        previous = p;
        p = p->next;
    }
    if (previous == NULL)
        head = NULL;
    else
        previous->next = NULL;
    printf("Deleted: %d\n", p->data);
    free(p);
}

static void delete_value(int key)
{
    Node *p = head, *previous = NULL;
    while (p != NULL && p->data != key) {
        previous = p;
        p = p->next;
    }
    if (p == NULL) {
        printf("Key not found.\n");
        return;
    }
    if (previous == NULL)
        head = p->next;
    else
        previous->next = p->next;
    printf("Deleted: %d\n", p->data);
    free(p);
}

static void display(void)
{
    const Node *p = head;
    if (p == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
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
    int choice, value, key;
    do {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert after a key\n");
        printf("4. Delete first\n5. Delete last\n6. Delete a key\n7. Display\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            free_list();
            return 1;
        }
        switch (choice) {
            case 1:
            case 2:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) { free_list(); return 1; }
                if (choice == 1) insert_first(value);
                else insert_last(value);
                break;
            case 3:
                printf("Enter key and new value: ");
                if (scanf("%d%d", &key, &value) != 2) { free_list(); return 1; }
                insert_after(key, value);
                break;
            case 4: delete_first(); break;
            case 5: delete_last(); break;
            case 6:
                printf("Enter key to delete: ");
                if (scanf("%d", &key) != 1) { free_list(); return 1; }
                delete_value(key);
                break;
            case 7: display(); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    free_list();
    return 0;
}
