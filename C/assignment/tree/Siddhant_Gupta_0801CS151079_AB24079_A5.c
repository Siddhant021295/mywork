#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=1;
struct tree
{
	char word[30];
	struct tree *l,*r;
};
typedef struct tree t;
/*to create a new node*/
t *getnode()
{
	t *cur;
	cur=(t*)malloc(sizeof(t));
	cur->l=cur->r=NULL;
	return cur;
}
/*fuction to insert word in the tree*/
t *insert(t *r,char word[])
{	
	if(r==NULL)
	{
		r=(t*)malloc(sizeof(t));
		r->l=r->r=NULL;
		strcpy(r->word,word);
		count++;	
	}
	else
	{
		if(count%2==0)
		{
			r->l = insert(r->l,word);
		}
		else
		{
			r->r = insert(r->r,word);
		}
	}
	return r;
}
int y=0;
/*search word in the tree*/
void search(t *r,char word[])
{	
		
	if(r->l!=NULL)
	{	
		search(r->l,word);
	}
	if(strcmp(word,r->word)==0)
	{	
		y=1;
	} 
	if(r->r!=NULL)
	{	
		search(r->r,word);
	}
}
int count1=0;
/*to display list*/
void display(t *r)
{

	if(r->l!=NULL)
	display(r->l);
	printf("%s\n",r->word);
	if(r->r!=NULL)
	display(r->r);
	
}
/*main content*/
void main()
{
	t *start,*current=NULL;
	FILE *fp1,*fp2;
	int i=0,e,h=0,g=0,x=0;
	fp1=fopen("para1.txt","r");
	char para1[500][30],ch,para1f[500][30],para2[500][30],para2f[500][30],l,yes,no,p,cho,new[20];
	
	while((ch=getc(fp1)) != EOF)
	{		
		h=0;
		fseek(fp1,-1,SEEK_CUR);
		fscanf(fp1,"%s",para1[i]);
		h=strlen(para1[i]);
		while(g<=h)
		{	
			if(para1[i][g]>='a'&& para1[i][g]<='z'||para1[i][g]>='A'&& para1[i][g]<='Z')
			{	
				para1f[i][g]=para1[i][g];
				if(para1f[i][g]>='A' && para1f[i][g]<='Z')
				{
					para1f[i][g]=para1f[i][g]+32;
				}
			}
			g++;
			para1f[i][g]='\0';
		}
		
		g=0;
		i++;
	}
	fclose(fp1);
	current=insert(current,para1f[i]);
	i--;
	while(i>=0)
	{	

		start=current;
		search(start,para1f[i]);		
		if(y==0)
		{
			x++;
			current=insert(current,para1f[i]);
			start=current;
		}	
		i--;
		y=0;
	}
	printf("\nwelcome to siddhant's dictionary\n");
	printf("\npara1 was added to the dictionary\n");
	fp2=fopen("para2.txt","r");
	i=0;h=0;g=0;	
	while((l=getc(fp2)) != EOF)
	{		
		h=0;
		fseek(fp2,-1,SEEK_CUR);
		fscanf(fp2,"%s",para2[i]);
		h=strlen(para2[i]);
		/*cleaning the word from any extra symbols and changing to small letters*/		
		while(g<=h)
		{	
			if(para2[i][g]>='a'&& para2[i][g]<='z'||para2[i][g]>='A'&& para2[i][g]<='Z')
			{	
				para2f[i][g]=para2[i][g];
				if(para2f[i][g]>='A' && para2f[i][g]<='Z')
				{
					para2f[i][g]=para2f[i][g]+32;
				}
			}
			g++;
			para2f[i][g]='\0';
		}
		g=0;
		i++;
	}
	i--;
	while(i>=0)
	{	

		start=current;
		search(start,para2f[i]);		
		if(y==0)
		{
			x++;
			printf("\n\tdo you want to insert the new word?\n\t1\tpress 'A' to add the word\n\t2\tpress 'I' to Ignore the word\n the word is \n'%s' \n",para2f[i]);
			scanf("%c",&yes);scanf("%c",&no);
			if(yes=='A'||yes=='a')
			{
				current=insert(current,para2f[i]);						
			}
			start=current;
		}	
		i--;
		y=0;
	}
	while(1)
	{
		printf("\nyou have the following choose\n2\tpress 'A' to add a new a word\n3\tany other key to end the program\n");
		scanf("%c",&cho);scanf("%c",&no);
		
	
		if(cho == 'A'||cho== 'a')
		{
			scanf("%s",new);scanf("%c",&no);
			current=insert(current,new);
			start=current;
		}
		else
			break;	
	}	
	printf("\n1\t press 'y' to display the dictionary\n");
	scanf("%c",&cho);scanf("%c",&no);
	if(cho=='Y'||cho=='y')
		{
			display(current);
		}
}



