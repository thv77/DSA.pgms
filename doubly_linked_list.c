#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int data; struct Node *prev,*next; } Node;
Node *head=NULL;
void insert_front(int x) { Node *n=malloc(sizeof *n); if(!n){puts("Allocation failed");return;} n->data=x;n->prev=NULL;n->next=head;if(head)head->prev=n;head=n; }
void insert_end(int x) { Node *n=malloc(sizeof *n),*p=head; if(!n){puts("Allocation failed");return;} n->data=x;n->next=NULL;if(!head){n->prev=NULL;head=n;return;}while(p->next)p=p->next;p->next=n;n->prev=p; }
void delete_value(int x) { Node *p=head;while(p&&p->data!=x)p=p->next;if(!p){puts("Key not found");return;}if(p->prev)p->prev->next=p->next;else head=p->next;if(p->next)p->next->prev=p->prev;free(p); }
void display(void) { Node *p=head;if(!p)puts("List is empty");while(p){printf("%d ",p->data);p=p->next;}puts(""); }
void reverse_display(void) { Node *p=head;if(!p){puts("List is empty");return;}while(p->next)p=p->next;while(p){printf("%d ",p->data);p=p->prev;}puts(""); }
int main(void) { int ch,x; do { printf("\n1.Insert front 2.Insert end 3.Delete value 4.Display forward 5.Display reverse 0.Exit\nChoice: ");if(scanf("%d",&ch)!=1)break;switch(ch){case 1:case 2:printf("Value: ");if(scanf("%d",&x)!=1)break;if(ch==1)insert_front(x);else insert_end(x);break;case 3:printf("Value to delete: ");if(scanf("%d",&x)==1)delete_value(x);break;case 4:display();break;case 5:reverse_display();break;case 0:break;default:puts("Invalid choice");}}while(ch!=0);while(head){Node*p=head;head=head->next;free(p);}return 0; }