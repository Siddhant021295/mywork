#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
	char state[30],ac_name[30],ac_type[5],cand_name[50],cand_sex,party[50],p_abrre[10];
	int year,ac_no,vote_rev,voter;
	struct node *next,*del100,*female,*actype,*winnerof,*independent,*partyname,*parremove,*male;
};
/*to creat nodes*/
typedef struct node N;
N *getnode()
{
	N *cur;
	cur=(N*)malloc(sizeof(N));
	cur->next=NULL;
	cur->winnerof=NULL;
	cur->female=NULL;
	cur->actype=NULL;
	cur->del100=NULL;	
	return cur;
}/*to display main list*/
void display(N *c)
{
	while(c->next!=NULL)
	{
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
	c=c->next;
	}
}
/*main list*/
void main()
{
	FILE *f;
	char ch,cate[3],ca[3],par[3];
	int num,choose,count=0;
	N *h,*start;
	f=fopen("Election_data.txt","r");
	start=getnode();
	h=start;
	while((ch=getc(f)) != EOF)
	{
		count++;/* to count the no of nodes*/
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
	printf("\nno of nodes are %d\n",count);
	printf("you have the following chooses \n1 display the main list\n");
	scanf("%d",&num);
	switch(num)
	{
		case 1:
		{
			display(start);break;
		}
		default :
		{
			printf("wrong choose...");
			exit(1);
		}	
	}
}

