#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL, *temp = NULL, *ptr = NULL, *prev = NULL, *current = NULL;

int item, key;

void insertFirst();
void insertLast();
void insertKey();
void deleteFirst();
void deleteLast();
void deleteKey();
void display();

void main()
{
    int n;

    printf("Menu:\n");
    printf("1.Insert at first.\n2.Insert at last.\n3.Insert after a key.\n4.Delete from the front.\n5.Delete from the end.\n6.Delete a key.\n7.Display.\n8.Exit\n");

    do
    {
        printf("Enter the choice:");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
                insertFirst();
                break;

            case 2:
                insertLast();
                break;

            case 3:
                insertKey();
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                deleteKey();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Have a nice day\n");
                exit(0);
                break;

            default:
                printf("Invalid operation");
                break;
        }
    } while (n != 8);
}

void insertFirst()
{
    temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory underflow");
    }
    else
    {
        printf("Enter the element to be inserted:");
        scanf("%d", &item);

        temp->data = item;
        temp->link = head;
        head = temp;
    }

    display();
    printf("\n");
}

void insertLast()
{
    temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory underflow");
        exit(0);
    }

    printf("Enter the element to be inserted:");
    scanf("%d", &item);

    if (head == NULL)
    {
        temp->data = item;
        temp->link = head;
        head = temp;
    }
    else
    {
        ptr = head;

        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }

        ptr->link = temp;
        temp->data = item;
        temp->link = NULL;
    }

    display();
    printf("\n");
}

void insertKey()
{
    temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory underflow");
        exit(0);
    }

    printf("Enter the element to be inserted:");
    scanf("%d", &item);

    printf("Enter the key:");
    scanf("%d", &key);

    ptr = head;

    while (ptr->data != key && ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    if (ptr->link == NULL)
    {
        printf("Search fails\n");
    }
    else
    {
        temp->data = item;
        temp->link = ptr->link;
        ptr->link = temp;
    }

    display();
    printf("\n");
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        exit(0);
    }

    printf("%d is deleted\n", head->data);

    prev = head;
    head = head->link;

    free((void*)prev);

    display();
    printf("\n");
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        exit(0);
    }

    prev = head;
    current = head;

    while (current->link != NULL)
    {
        prev = current;
        current = current->link;
    }

    prev->link = NULL;

    printf("%d is deleted\n", current->data);

    free((void*)current);

    display();
    printf("\n");
}

void deleteKey()
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        exit(0);
    }

    printf("Enter the key:");
    scanf("%d", &key);

    prev = head;
    current = head;

    while (current->data != key && current->link != NULL)
    {
        prev = current;
        current = current->link;
    }

    if (current->link == NULL)
    {
        printf("Search fails\n");
    }
    else
    {
        printf("%d is deleted\n", current->data);
        prev->link = current->link;
    }

    display();
    printf("\n");
}

void display()
{
    if (head == NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        ptr = head;

        while (ptr != NULL)
        {
            printf("%d \t", ptr->data);
            ptr = ptr->link;
        }
    }
}
