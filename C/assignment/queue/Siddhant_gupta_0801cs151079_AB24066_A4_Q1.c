#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*structure of the queue*/
struct Queue
{
	char num[15];
	char date[15];
	char time[15];
	char status[15];
	char duration[5];
	struct Queue *next,*previous;
};
typedef struct Queue q;
/*creating a new node*/
q *getnode()
{
	q *cur;
	cur = (q*)malloc(sizeof(q));
	cur->next=NULL;
	cur->previous=NULL;
	return cur;
}
/*display outgoing call*/
void displayo(q *p)
{
	p=p->previous;
	while(p!=NULL)
	{
		printf("%s\t%s\t%s\t%s\t%s\n",p->num,p->date,p->time,p->status,p->duration);
		p=p->previous;
	}
}
/*display incoming calls*/
void displayi(q *p)
{
	p=p->previous;
	while(p!=NULL)
	{
		printf("%s\t%s\t%s\t%s\t%s\n",p->num,p->date,p->time,p->status,p->duration);
		p=p->previous;
	}
}
/*display missed call*/
void displaym(q *p)
{
	p=p->previous;
	while(p!=NULL)
	{
		printf("%s\t%s\t%s\t%s\t%s\n",p->num,p->date,p->time,p->status,p->duration);
		p=p->previous;
	}
} 
/*main content*/
void main()
{
	char ch,num[10],date[10],time[10],status[10],duration[10],j;
	int choice1,choice2,choice3;
	q *ofront,*olast,*ilast,*mlast,*ifront,*mfront,*temp;
	olast = getnode();
	ilast = getnode();
	mlast = getnode();
	ofront=olast;
	ifront=olast;
	mfront=mlast;
	FILE *f;
	f=fopen("mn.txt","r");
	while(feof(f)==0)/*to add call to different list*/ 
	{
		fscanf(f,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",num,date,time,status,duration);
		if(status[0]=='m')
		{
			strcpy(mlast->num,num);
		    	strcpy(mlast->date,date);
		    	strcpy(mlast->time,time);
		    	strcpy(mlast->status,status);
		    	strcpy(mlast->duration,duration);
			mlast->next=getnode();
			mlast->next->previous=mlast;
			mlast=mlast->next;
		}	
		if(status[0]=='i')
		{
				
			strcpy(ilast->num,num);
		    	strcpy(ilast->date,date);
		    	strcpy(ilast->time,time);
		    	strcpy(ilast->status,status);
		    	strcpy(ilast->duration,duration);
		    	ilast->next=getnode();
		    	ilast->next->previous=ilast;
			ilast=ilast->next;
		}
		if(status[0]=='o')
		{
			strcpy(olast->num,num);
			strcpy(olast->date,date);
            		strcpy(olast->time,time);
            		strcpy(olast->status,status);
            		strcpy(olast->duration,duration);
            		olast->next=getnode();
            		olast->next->previous=olast;
			olast=olast->next;
		}
	}
	while(1)
	{
		printf("\nPress 1 to enter new call details..\n");
		printf("Press 2 to review missed calls..\n");
	     	printf("Press 3 to review incoming calls..\n");
	     	printf("Press 4 to review outgoing calls..\n");
	     	printf("Press 5 to exit..\n\n");
	     	printf("Your choice goes here: ");
     		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1:/*enter details of new call*/
			{
				printf("\nenter the new entry for the list\n1 MISSED CALL\n2 INCOMING CALL\n3 OUTGOING CALL\n");
				scanf("%d",&choice2);
				switch(choice2)
				{
					case 1:
					{
						temp=mfront;
						mfront=mfront->next;
						mfront->previous=NULL;
						free(temp);
						printf("enter the no\t");
						scanf("%s",mlast->num);
						printf("\nenter date\t");
						scanf("%s",mlast->date);
						printf("\nenter time\t");
						scanf("%s",mlast->time);
						strcpy(mlast->status,"missed");
						strcpy(mlast->duration,"0");
						mlast->next=getnode();
						mlast->next->previous=mlast;
						mlast=mlast->next;
						break;						
					}
					case 2:
					{
						temp=ifront;
						ifront=ifront->next;
						ifront->previous=NULL;
						free(temp);
						printf("enter the no\t");
						scanf("%s",ilast->num);
						printf("\nenter date\t");
						scanf("%s",ilast->date);
						printf("\nenter time\t");
						scanf("%s",ilast->time);
						strcpy(ilast->status,"incoming");
						printf("\nenter the duration\t");
						scanf("%s",ilast->duration);
						ilast->next=getnode();
						ilast->next->previous=ilast;
						ilast=ilast->next;
						break;						
					}
					case 3:
					{
						temp=ofront;
						ofront=ofront->next;
						ofront->previous=NULL;
						free(temp);
						printf("enter the no\t");
						scanf("%s",olast->num);
						printf("\nenter date\t");
						scanf("%s",olast->date);
						printf("\nenter time\t");
						scanf("%s",olast->time);
						strcpy(olast->status,"outgoing");
						printf("\nenter the duration\t");
						scanf("%s",olast->duration);
						olast->next=getnode();
						olast->next->previous=olast;
						olast=olast->next;
						break;						
					}
				}
				break;
			}
			case 2:/*review the missed call*/
			{	
				printf("\nreview the MISSED CALL\n");
				displaym(mlast);
				printf("\nEnter 1 to call back..\n");
				printf("Enter 2 to call back later..\n");
     				printf("Enter 3 to ignore/never call back later..\n");
     				printf("Your choice goes here: ");
     				scanf("%d",&choice3);
				switch(choice3)
				{
					case 1:
					{
						temp=ofront;
						ofront=ofront->next;
						ofront->previous=NULL;
						free(temp);
						strcpy(olast->num,mlast->previous->num);
						printf("\nenter date\t");
						scanf("%s",olast->date);
						printf("\nenter time\t");
						scanf("%s",olast->time);
						strcpy(olast->status,"outgoing");
						printf("\nenter the duration\t");
						scanf("%s",olast->duration);
						olast->next=getnode();
						olast->next->previous=olast;
						olast=olast->next;	break;	
					}
					case 2:
					{
						printf("call back later");break;
					}
					case 3:
					{
						temp=mlast->previous;
						mlast->previous=mlast->previous->previous;
						mlast->previous->next=NULL;break;
						free(temp);						
					}
				}break;
				
			}
			case 3:/*review the incoming call*/
			{
				printf("\nreview the INCOMING CALL\n");
				displayi(ilast);
				printf("\nEnter 1 to call back..\n");
				printf("Enter 2 to call back later..\n");
     				printf("Enter 3 to ignore/never call back later..\n");
     				printf("Your choice goes here: ");
     				scanf("%d",&choice3);
				switch(choice3)
				{
					case 1:
					{
						temp=ofront;
						ofront=ofront->next;
						ofront->previous=NULL;
						free(temp);
						strcpy(olast->num,mlast->previous->num);
						printf("\nenter date\t");
						scanf("%s",olast->date);
						printf("\nenter time\t");
						scanf("%s",olast->time);
						strcpy(olast->status,"outgoing");
						printf("\nenter the duration\t");
						scanf("%s",olast->duration);
						olast->next=getnode();
						olast->next->previous=olast;
						olast=olast->next;	break;	
					}
					case 2:
					{
						printf("call back later");break;
					}
					case 3:
					{
						temp=ilast->previous;
						ilast->previous=ilast->previous->previous;
						ilast->previous->next=NULL;
						free(temp);			break;		
					}
				}				break;
			}
			case 4:/*review the outgoing call*/
			{
				printf("\nreview the OUTGOING CALL\n");
				displayo(olast);
				printf("\nEnter 1 to call back..\n");
				printf("Enter 2 to call back later..\n");
     				printf("Enter 3 to ignore/never call back later..\n");
     				printf("Your choice goes here: ");
     				scanf("%d",&choice3);
				switch(choice3)
				{
					case 1:
					{
						temp=ofront;
						ofront=ofront->next;
						ofront->previous=NULL;
						free(temp);
						strcpy(olast->num,mlast->previous->num);
						printf("\nenter date\t");
						scanf("%s",olast->date);

						strcpy(olast->status,"outgoing");
						printf("\nenter the duration\t");
						scanf("%s",olast->duration);
						printf("\nenter time\t");
						scanf("%s",olast->time);						
						olast->next=getnode();
						olast->next->previous=olast;
						olast=olast->next;		break;
					}
					case 2:
					{
						printf("call back later");break;
					}
					case 3:
					{
						temp=olast->previous;
						olast->previous=olast->previous->previous;
						olast->previous->next=NULL;
						free(temp);			break;			
					}
				}break;	
			}
			case 5:
			{
				exit(1);
			}	
		}
	}

