#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
	char state[30],ac_name[30],ac_type[5],cand_name[50],cand_sex,party[50],p_abrre[10];
	int year,ac_no,vote_rev,voter;
	struct node *next,*del100,*female,*actype,*winnerof,*independent,*partyname,*parremove;
};
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
	cur->partyname=NULL;
	cur->parremove=NULL;
	return cur;
}
/*add the votes of people who did not vote*/
long int list(N *c,int y)
{
		long int num;
		num=0;
		while(c->winnerof!=NULL)
		{
			if(c->year==y)
			{
				num=num+c->voter-c->vote_rev;
			}
			c=c->winnerof;
			
		}
	printf("\nno of electors who did not vote in a year %d are %ld\n",y,num);
return num;		
}
/*total the percentage of male and female*/
void percentage(N *fem)
{
	float male=0,female=0,total=0;int i=0;
	N *start,*previous;
	float per_male,per_female;
	while(fem->next!=NULL)
   	{
		total++;
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
			female++;
		}
	     	fem=fem->next;
	} 
	printf("%f\n",female);
	printf("%f\n",total);
	male=total-female;
	printf("%f\n",male);
	per_male=(float)(male/total)*100;
	per_female=(float)(female/total)*100;
	printf("\npercentage of male = %f",per_male);
	printf("\npercentage of female = %f\n",per_female);
}
/*fuction cal the no of votes of every party*/
int add(N *cat,char ch[50],int y)
{	
	int i=0,no=0;long int votes=0;  
	while(cat->next!=NULL)
   	{
  		if((strcmp(cat->p_abrre,ch)==0)&&(cat->year==y))
	  	{	
			votes=votes+cat->vote_rev;
		}
	     	cat=cat->next;
	} 
	if(votes!=0)
	{
		printf("\nno of votes of same party in year %d are %ld\n",y,votes);
	}
return votes;
}
/*create list of winner*/
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

/*main content*/
void main()
{
	FILE *f;
	char ch,cate[3],ca[3],par[3];
	int num,choose,count=0,y,r[30],i,j;long int s[1000];
	N *h,*start,*o;
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
	printf("\nno of nodes are %d\n",count);/*to count the no of nodes*/
	percentage(start);
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
		{
			printf("wrong choose....");
				
		}
	}
		y=1977;i=0;
		while (y<=2011)
		{	
			j=i;
			r[i]=add(start,par,y);
			y++;i++;
		}		
		for(i=1;i<j;++i) 
		{
			if(r[0]<r[i])
				{
				r[0]=r[i];
				}
		}
    		printf("\nthe greatest no of votes  = %d\n",r[0]);
	 o= winner(start);
	y=1977;i=0;
	while(y<=2012)
	{
		j=i;
		start=o;
		s[i]=list(start,y);
		y++;i++;
	}
	for(i=1;i<j;++i) 
		{
			if(s[0]<s[i])
				{
				s[0]=s[i];
				}
		}
	printf("\nthe greatest no of votes  = %ld\n",s[0]);
fclose(f);

}
