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
/*to creat a node*/
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
/*to display main list*/
void display(N *c)
{
	while(c->next!=NULL)
	{
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
	c=c->next;
	}
}
/*to display female list*/
void fdisplay(N *c)
{	
	while(c->female!=NULL)
	{
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
	c=c->female;
	}
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
}
/*to display candidate of same ac type*/
void acdisplay(N *c)
{
	while(c->actype!=NULL)
	{
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
	c=c->actype;
	}
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
}
/*to display on basic of party name*/
void adddisplay(N *c)
{
	while(c->partyname!=NULL)
	{
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
	c=c->partyname;
	}
	printf("%s\t%d\t%d\t%s\t%s\t%s\t\t%c\t\t%s\t%s\t%d\t%d\n",c->state,c->year,c->ac_no,c->ac_name,c->ac_type,c->cand_name,c->cand_sex,c->party,c->p_abrre,c->vote_rev,c->voter);
}
/*to creat on the basic of party name*/
N *add(N *cat,char ch[50])
{	
	int i=0;
	N *start,*previous;  
	while(cat->next!=NULL)
   	{
  		if(strcmp(cat->p_abrre,ch)==0)
	  	{	
			if(i<1)
			{	
				i++;
				start=cat;
				previous=cat;			
			}
			else
			{	
				previous->partyname=cat;
				previous=cat;
			}
		}
	     	cat=cat->next;
	} 
return start;
}
/*to creat a linklist of female*/
N *female(N *fem)
{	
	int i=0;
	N *start,*previous;  
	while(fem->next!=NULL)
   	{
  		if(fem->cand_sex=='F')
	  	{	
			if(i<1)
			{
				i++;
				start=fem;
				previous=fem;			
			}
			else
			{	
				previous->female=fem;
				previous=fem;
			}
		}
	     	fem=fem->next;
	} 
	return start;
}
/*to creat a link list of ac type*/
N *actypecat(N *cat,char ch[3])
{	
	int i=0;
	N *start,*previous;  
	while(cat->next!=NULL)
   	{
  		if(strcmp(cat->ac_type,ch)==0)
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
				previous->actype=cat;
				previous=cat;
			}
		}
	     	cat=cat->next;
	} 
return start;
}
/*main program*/
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
	printf("you have the following chooses \n1 display the main list\n2 list of female candidate\n3 list of people with same Assembly constituency reservation status\n4 display on the basic of party name\n");
	scanf("%d",&num);

switch(num)
	{
		case 1:
		{
			display(start);break;
		}
		case 2:
		{
			start=female (start);
			fdisplay(start);
			break;
		}
		case 3:
		{	
			printf("which cat people do you want\n1 GEN\n2 ST\n3 SC\n");			
			scanf("%d",&choose);
			switch(choose)
			{
				case 1:
				{
					strcpy(cate,"GEN");break;
				}
				case 2:
				{
					strcpy(cate,"ST");break;
				}
				case 3:
				{
					strcpy(cate,"SC");break;
				}
			
				default :
				{				
				printf("wrong choose....");
				exit(1);
				}
							
			}
			 start=actypecat(start,cate);
			 acdisplay(start);
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
					strcpy(par,"JNP");break;
				}
				case 2:
				{
					strcpy(par,"IND");break;
				}
				case 3:
				{
					strcpy(par,"BJP");break;
				}
				case 4:
				{
					strcpy(par,"DDP");break;
				}
				case 5:
				{
					strcpy(par,"SHS");break;
				}
				case 6:
				{
					strcpy(par,"BSP");break;
				}
				case 7:
				{
					strcpy(par,"INC");break;
				}
				case 8:
				{
					strcpy(par,"SAP");break;
				}
				case 9:
				{
					strcpy(par,"SP");break;
				}
				case 10:
				{
					strcpy(par,"RPI");break;
				}				
				default :
				printf("wrong choose....");
				
							
			}
			start=add(start,par);
			adddisplay(start);
			break;
		}
		default :
		{
			printf("wrong choose...");
		}
	}
fclose(f);
}
