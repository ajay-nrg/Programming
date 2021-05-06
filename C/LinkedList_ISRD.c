#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
    /* data */
}node;

node *head;

void add_beg(int d){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = d;
    temp->next = head;
    head = temp;
}

void add_after(int d, int loc){
    node *cur,*temp;
    int i;
    cur = head;
    for(i=0;i<loc;i++){
        cur = cur->next;
        if(cur == NULL){
            printf("There are less than %d elements in a list\n",loc);
            return;
        }
    }
    temp = (node*)malloc(sizeof(node));
    temp->data = d;
    temp->next = cur->next;
    cur->next = temp;
}

void add_end(int d){
    node *temp, *cur;
    if(head == NULL){
        temp = (node*)malloc(sizeof(node));
        temp->data = d;
        temp->next = NULL;
        head = temp;
    }
    else{
        temp = (node*)malloc(sizeof(node));
        temp->data = d;
        temp->next = NULL;
        cur = head;
        while(cur->next!=NULL)
            cur = cur->next;
        cur->next = temp;
    }
}

void del_beg(){
    if(head!=NULL){
        node *temp;
        temp = head;
        head = head->next;
        free(temp);
    }
    else
        printf("Nothing to delete\n");
}  

void del_end(){
    node *prev, *cur;
    if(head!=NULL){
        cur = head;
        while(cur->next!=NULL){
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        free(cur);
    }
    else
        printf("Nothing to delete\n");
}

void del(int d){
    node *prev, *cur;
    if(head!=NULL){
        cur = head;
        while(cur!=NULL){
            if(cur->data == d){
                if(cur == head)
                    head = cur->next;
                else   
                    prev->next = cur->next;
                free(cur);
                    return;
            }
            else{
                prev = cur;
            cur = cur->next;
            }
        }
    }
    else
        printf("Nothing to delete\n");
}

void display(){
    node *cur;
    if(head!=NULL){
        cur = head;
        printf("\n");
        while(cur!=NULL){
            printf("%d\t",cur->data);
            cur=cur->next;
        }
        printf("\n");
    }
    else
        printf("Nothing to delete\n");
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

