#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
	char state[30],ac_name[30],ac_type[5],cand_name[50],cand_sex,party[50],p_abrre[10];
	int year,ac_no,vote_rev,voter;
	struct node *next,*del100,*female,*actype,*winnerof,*independent,*partyname,*parremove,*male;
};
typedef struct node N;
/*function for creating a node*/
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
}
/*fuction to display main list*/
void display(N *c)
{
	while(c->next!=NULL)
	{
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
	c=c->next;
	}
}
/*fuction to display candidates with more than 100votes*/
void deldisplay(N *c)
{
	while(c->del100!=NULL)
	{
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
	c=c->del100;
	}
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
}
/*display all party except the party you selected */
void deletedisplay(N *c)
{
	while(c->parremove!=NULL)
	{
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
	c=c->parremove;
	}
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
}
/*display only independent candidates*/
void idisplay(N *c)
{
	while(c->independent!=NULL)
	{
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
	c=c->independent;
	}
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
}
/*function to del according to the party name*/
N *del(N *cat,char ch[50])
{	
	int i=0;
	N *start,*previous;  
	while(cat->next!=NULL)
   	{
  		if(strcmp(cat->p_abrre,ch)!=0)
	  	{	
			if(i<1)
			{	
				printf("%d",i);
				i++;
				start=cat;
				previous=cat;			
			}
			else
			{	
				previous->parremove=cat;
				previous=cat;
			}
		}
	     	cat=cat->next;
	} 
return start;
}
/*function to delete the people with less than 100 votes*/
N *delete100(N *head)
{
	int i=0;
	N *start,*previous;
	while(head->next!=NULL)
	{
		if(head->vote_rev>100)
	  	{	
			if(i<1)
			{
				i++;
				start=head;
				previous=head;			
			}
			else
			{	
				previous->del100=head;
				previous=head;
			}
		}
	     	head=head->next;
	} 
return start;
}
/*canditates who represented the indepentent party*/
N *indepen(N *head)
{
	int i=0;
	N *start,*previous;
	while(head->next!=NULL)
	{
		if((strcmp(head->p_abrre,"IND")) != 0)
	  	{	
			if(i<1)
			{
				i++;
				start=head;
				previous=head;			
			}
			else
			{	
				previous->independent=head;
				previous=head;
			}
		}
	     	head=head->next;
	} 
return start;
}
/*main content*/
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
	printf("\nno of nodes are %d\n",count);
	printf("you have the following chooses \n1 display the main list\n2 delete the people with less then 100 votes\n3 list without the independent candidate\n4 which party do you not want\n");
	scanf("%d",&num);
	switch(num)
	{
		case 1:
		{
			display(start);break;
		}	
		case 2:
		{
			start=delete100(start);
			deldisplay(start);
			break;
		}
		case 3:
		{
			start=indepen(start);
			idisplay(start);
			break;
		}
		case 4:
		{	
			printf("which party people do you want\n1 JNP\n2 IND\n3 BJP\n4 DDP\n5 SHS\n6 BSP\n7 INC\n8 SAP\n9 SP\n10 RPI\n");			
			scanf("%d",&choose);
			switch(choose)
			{
				case 1:
				{
					strcpy(ca,"JNP");break;
				}
				case 2:
				{
					strcpy(ca,"IND");break;
				}
				case 3:
				{
					strcpy(ca,"BJP");break;
				}
				case 4:
				{
					strcpy(ca,"DDP");break;
				}
				case 5:
				{
					strcpy(ca,"SHS");break;
				}
				case 6:
				{
					strcpy(ca,"BSP");break;
				}
				case 7:
				{
					strcpy(ca,"INC");break;
				}
				case 8:
				{
					strcpy(ca,"SAP");break;
				}
				case 9:
				{
					strcpy(ca,"SP");break;
				}
				case 10:
				{
					strcpy(ca,"RPI");break;
				}				
				default :
				printf("wrong choose....");
				
			}
			start=del(start,par);
			deletedisplay(start);
			break;
		}		
	}
fclose(f);
}
