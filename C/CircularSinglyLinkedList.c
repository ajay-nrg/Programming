#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
    /* data */
}node;

node *head=NULL,*temp,*cur,*prev;

void add_beg(int n){
    cur = (node*)malloc(sizeof(node));
    cur->next = NULL;
    cur->data = n;
    if(head!=NULL){
        temp=head;
        while(temp->next!=head)
            temp = temp->next;
        temp->next = cur;
        cur->next = head;
        head = cur;
    }
    else{
        head=cur;
        head->next = head;
    }
}

void display(){
    temp=head;
    while(temp!=head){
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
            // case 1: printf("Enter value\n");
            //         scanf("%d",&n);
            //         add_end(n);
            //         break;
            // case 2: printf("Enter value\n");
            //         scanf("%d",&n);
            //         printf("Insert position\n");
            //         scanf("%d",&p);
            //         add_after(n,p);
            //         break;
            case 3: printf("Enter value\n");
                    scanf("%d",&n);
                    add_beg(n);
                    break;
            // case 4: del_beg(n);
            //         break;
            // case 5: printf("Enter value to be deleted\n");
            //         scanf("%d",&n);
            //         del(n);
            //         break;
            // case 6: del_end(n);
            //         break;
            case 7: display();
                    break;
            case 8: return 0;
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

