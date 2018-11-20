#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
	char state[30],ac_name[30],ac_type[5],cand_name[50],cand_sex,party[50],p_abrre[10];
	int year,ac_no,vote_rev,voter;
	struct node *next,*winnerof;
};
typedef struct node N;
/*creating a new node*/
N *getnode()
{
	N *cur;
	cur=(N*)malloc(sizeof(N));
	cur->next=NULL;
	cur->winnerof=NULL;	
	
	return cur;
}
/*to display the main list*/
void display(N *c)
{
	while(c->next!=NULL)
	{
		printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
		c=c->next;
	}
}
/*to display the winner list*/
void wdisplay(N *c)
{
	while(c->winnerof!=NULL)
	{
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
	c=c->winnerof;
	}
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
}
/*function to creat the winner list*/
N *winner(N *start1)
{
	N *temp,*temp1,*list,*start;
	int i=0,j=0;
	temp=start1;
	temp1=start1->next;
	while(temp1->next!=NULL)
	{
		if(i!=0)
		{
			temp=temp1;
			temp1=temp1->next;
			
		}
		i++;
		while((temp->year==temp1->year)&&(temp->ac_no==temp1->ac_no)&&(temp1->next!=NULL))
		{
			if(temp->vote_rev>=temp1->vote_rev)
			{
				temp=temp;			
			}
			else
			{
				temp=temp1;
			}
			temp1=temp1->next;
			
		}
		
		if(j==0)
		{
			list=temp;
			start=temp;
			j++;
		}
		else
		{
			list->winnerof=temp;
			list=list->winnerof;
		}
		
	}
return start;
}
/*main program*/
void main()
{
	FILE *f;
	char ch,cate[3],ca[3],par[3];
	int num,choose,count= 0;
	N *h,*start;
	f=fopen("Election_data.txt","r");
	start=getnode();
	h=start;
	while((ch=getc(f)) != EOF)
	{
		count++;
		fseek(f,-1,SEEK_CUR);
		fscanf(f,"%[^\t]\t%d\t%d\t%[^\t]\t%s\t%[^\t]\t",h->state,&h->year,&h->ac_no,h->ac_name,h->ac_type,h->cand_name);
		if((h->year==2010)&&(strcmp(h->state,"Bihar")==0))
		{	
		h->cand_sex='X';
		}
		else
		{
		fscanf(f,"%c\t",&h->cand_sex);
		}
		if(h->year<=2004)
		{
			fscanf(f,"%[^\t]\t",h->party);
		}
		if(((h->year>=2005)&&(h->year<=2007))&&((strcmp(h->state,"Jharkhand")!=0)||(strcmp(h->state,"Manipur")!=0)||(strcmp(h->state,"Maghalaya")!=0)))
		{
			fscanf(f,"%[^\t]\t",h->party);
		}

		if((h->year>=2008)&&(strcmp(h->state,"Bihar")==0))
		{
			fscanf(f,"%[^\t]\t",h->party);
		}
		fscanf(f,"%[^\t]\t%d\t%d\n",h->p_abrre,&h->vote_rev,&h->voter);
			h->next=getnode();
			h=h->next;
	}
	printf("no of nodes are %d",count);
	printf("you have the following chooses \n1 display the main list\n2 display the list of winner candidate\n");
	scanf("%d",&num);
	switch(num)
	{
		case 1:
		{
			display(start);break;
		}
		case 2:
		{
			start=winner(start);
			wdisplay(start);
			break;
		}
		default :
		{
			printf("wrong choose...");
		}
	}

}
