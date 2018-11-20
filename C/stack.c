#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX];
int pop();
void push(int item);
void Display();
int top =-1;

int pop(){
    if (top ==-1){
        printf("Empty");
        exit(1);
    }
    else{
        return a[top--];
    }
}
void push(int item){
    if (top==MAX-1){
        printf("Full");

    }
    else{
        top++;
        a[top]=item;
    }
}
void Display(){
    if (top==-1){
        printf("Empty");
    }
    else{
        for(int i=0;i<top;i++){
            printf("%d",a[i]);
		}
		printf("\n");
    }
}
void main(){
    int choice,item;
	while(1)
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1 :
			printf("Enter the item to be pushed : ");
			scanf("%d",&item);
			push(item);
			break;
		 case 2:
			item = pop();
			printf("Popped item is : %d\n",item );
			break;
		 case 3:
			Display();
			break;
		 case 4:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}