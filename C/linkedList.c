#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    /* data */
    int data;
    struct node *next;
}node;

struct node* head = NULL;
struct node* cur = NULL;
struct node* tail = NULL;
struct node* prev;
struct node* temp;

void insert_at_end(int val){
    cur = (node*)malloc(sizeof(node));
    cur->data = val;
    cur->next = NULL;
    if(head==NULL){
        head = cur;
    }    
    if(head->next==NULL){
        head->next = cur;
        tail = cur;
    }
    else{
        tail->next = cur;
        tail = cur;
    }
}

void insertAfter(int val,int p){
    int c=1;
    temp = (node*)malloc(sizeof(node));
    prev = (node*)malloc(sizeof(node));
    prev =
    temp->data=val;
    temp->next=NULL;
    cur = head;
    while(c==p){
        prev=cur;
        cur=cur->next;
        c++;
    }
    prev->next = temp;
    temp->next = cur;
}

void insert_at_head(int val){
    temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = head;
    head = temp;
}

void display(){
    cur=head;
    while(cur!=NULL){
        printf("%d\t",cur->data);
        cur=cur->next;
    }
    printf("\n");
}


int main(){
    int n,ch,p;
    while(1){
        printf(" 1.Insert At End\n 2.Insert After\n 3.Insert At Head\n 9.Display\n 10.Exit\n");
        printf("Enter ur choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter value\n");
                    scanf("%d",&n);
                    insert_at_end(n);
                    break;
            case 2: printf("Enter value\n");
                    scanf("%d",&n);
                    printf("Insert position\n");
                    scanf("%d",&p);
                    insertAfter(n,p);
                    break;
            case 3: printf("Enter value\n");
                    scanf("%d",&n);
                    insert_at_head(n);
                    break;
            case 9: display();
                    break;
            case 10: return 0;
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}