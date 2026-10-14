/* Singly Linked List Operations in C */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;

void insertFirst(void);
void insertLast(void);
void insertKey(void);
void deleteFirst(void);
void deleteLast(void);
void deleteKey(void);
void display(void);

int main(void)
{
    int choice;

    do {
        printf("\nSingly Linked List Menu\n");
        printf("1. Insert at first\n");
        printf("2. Insert at last\n");
        printf("3. Insert after a key\n");
        printf("4. Delete from the front\n");
        printf("5. Delete from the end\n");
        printf("6. Delete a key\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1: insertFirst(); break;
            case 2: insertLast(); break;
            case 3: insertKey(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: deleteKey(); break;
            case 7: display(); break;
            case 8: printf("Have a nice day!\n"); break;
            default: printf("Invalid operation.\n");
        }
    } while (choice != 8);

    while (head != NULL) {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }

    return 0;
}

void insertFirst(void)
{
    struct node *temp = malloc(sizeof *temp);

    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the element: ");
    if (scanf("%d", &temp->data) != 1) {
        free(temp);
        printf("Invalid input.\n");
        return;
    }

    temp->link = head;
    head = temp;
    display();
}

void insertLast(void)
{
    struct node *temp = malloc(sizeof *temp);
    struct node *ptr;

    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the element: ");
    if (scanf("%d", &temp->data) != 1) {
        free(temp);
        printf("Invalid input.\n");
        return;
    }

    temp->link = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        ptr = head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }

    display();
}

void insertKey(void)
{
    struct node *ptr = head;
    struct node *temp;
    int key;

    printf("Enter the key: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input.\n");
        return;
    }

    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key not found.\n");
        return;
    }

    temp = malloc(sizeof *temp);
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the element to insert: ");
    if (scanf("%d", &temp->data) != 1) {
        free(temp);
        printf("Invalid input.\n");
        return;
    }

    temp->link = ptr->link;
    ptr->link = temp;
    display();
}

void deleteFirst(void)
{
    struct node *temp;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    temp = head;
    printf("%d is deleted.\n", temp->data);
    head = head->link;
    free(temp);
    display();
}

void deleteLast(void)
{
    struct node *ptr = head;
    struct node *prev = NULL;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }

    printf("%d is deleted.\n", ptr->data);

    if (prev == NULL) {
        head = NULL;
    } else {
        prev->link = NULL;
    }

    free(ptr);
    display();
}

void deleteKey(void)
{
    struct node *ptr = head;
    struct node *prev = NULL;
    int key;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Enter the key to delete: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input.\n");
        return;
    }

    while (ptr != NULL && ptr->data != key) {
        prev = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key not found.\n");
        return;
    }

    printf("%d is deleted.\n", ptr->data);

    if (prev == NULL) {
        head = ptr->link;
    } else {
        prev->link = ptr->link;
    }

    free(ptr);
    display();
}

void display(void)
{
    struct node *ptr = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
