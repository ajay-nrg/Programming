#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
    /* data */
}node;

node *head=NULL,*cur,*temp,*prev;

void add_end(int n){
    cur = (node*)malloc(sizeof(node));
    cur->next = NULL;
    cur->data = n;
    cur->prev = NULL;
    if(head==NULL){
        head = cur;
    }
    else {
        temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = cur;
        cur->prev = temp;
    }
}
void add_beg(int n){
    cur = (node*)malloc(sizeof(node));
    cur->next = NULL;
    cur->data = n;
    cur->prev = NULL;
    if(head==NULL){
        head = cur;
    }
    else{
        head->prev = cur;
        cur->next = head;
        head = cur;
    }
}

void add_after(int n,int p){
    int c=0;
    cur = (node*)malloc(sizeof(node));
    cur->next = NULL;
    cur->data = n;
    cur->prev = NULL;
    temp = head; 
    while(temp->next!=NULL){
        if(c == p){
            break;
        }
        c++;
        temp = temp->next;
    }
    temp->next->prev = cur;
    cur->prev = temp;
    cur->next = temp->next;
    temp->next = cur;
}

void del_end(){
    if(head!=NULL){
        temp=head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
    }
    else
        printf("Nothing to delete\n");
}

void del_beg(){
    if(head!=NULL){
        temp = head;
        head = head->next;
        temp->next->prev = NULL;
        free(temp);
    }
    else
        printf("Nothing to delete\n");
}

void del(int p){
    if(head!=NULL){
        temp = head;
        while(temp->next!=NULL){
            if(p == temp->data)
                break;
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
}

void display(){
    temp = head;
    printf("The list is \n");
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int n,ch,p;
    while(1){
        printf(" 1.Insert At End\n 2.Insert After\n 3.Insert At Head\n 4.Delete Head\n 5.Delete Specific Node\n 6.Delete End\n 7.Display\n 8.Exit\n");
        printf("Enter ur choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter value\n");
                    scanf("%d",&n);
                    add_end(n);
                    break;
            case 2: printf("Enter value\n");
                    scanf("%d",&n);
                    printf("Insert position\n");
                    scanf("%d",&p);
                    add_after(n,p);
                    break;
            case 3: printf("Enter value\n");
                    scanf("%d",&n);
                    add_beg(n);
                    break;
            case 4: del_beg(n);
                    break;
            case 5: printf("Enter value to be deleted\n");
                    scanf("%d",&n);
                    del(n);
                    break;
            case 6: del_end(n);
                    break;
            case 7: display();
                    break;
            case 8: return 0;
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}