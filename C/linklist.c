#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *next;
    int data;
};
typedef struct Node n;
void Display(n *start){
    while(start!=NULL){
        printf("%d",start->data);
        start=start->next;
    }
}
void removedata(n *start,int remove)
{
    n *re; 
    while(start->next!=NULL)
    {
        if (start->next->data==remove)
        {
          printf("data removed is %d",remove);
          
          if (start->next->next!=NULL)
          {
            start->next=start->next->next;  
          }
          else
          {
              start->next=NULL;
          }
          break;
        }
        start=start->next;
    }
}

void main(){
    n *start=NULL;
    n *end=NULL;
    int choices,data,remove;
    while(1){
        printf("you have the following choices \n1 insert in linklist\n2 delete from the list\n3 display the list");
        scanf("%d",&choices);
        switch(choices)
        {
            case 1:
                printf("enter the element");
                scanf("%d",&data);
                if (start==NULL){
                    start=end= (n*)malloc(sizeof(n*));
                    start->data=data;
                }
                else
                {
                    
                    end->next=(n*)malloc(sizeof(n *));
                    end =end->next;
                    end->data=data;
                }
                break;
            case 2:
                scanf("%d",&remove);

                if (start==NULL){
                    printf("Empty");
                }
                else if(start->next==NULL && start->data==remove){
                    start = end=NULL ;
                }
                else if(start->data==remove){
                    start=start->next;
                }
                else{
                    removedata(start,remove);
                }
                break;
            case 3:
                Display(start);
                break;
            case 4:break;
            default: printf("wrong choice");
        }
    }
}
