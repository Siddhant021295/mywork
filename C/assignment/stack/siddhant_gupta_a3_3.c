#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
char leftstack[MAX];
char rightstack[MAX];
int lefttop=-1;
int righttop=-1;
char popleft();
void cursor();
void backspace();
char popright();
void pushleft(char );
void pushright(char );
void insert();
void show();
void delete();
/*main function*/
void main()
{
	int wish;
	char y;
	do
	{
	printf("you have the following option\n1\tinsert\n2\tdelete\n3\tbackspace\n4\tcursor\n5\texit\n");
	scanf("%d",&wish);	
	switch(wish)
		{
			case 1:
			{
				insert();
				break;
			}
			case 2:
			{
				delete();
				break;
			}
			case 3:
			{
				backspace();
				break;
			}
			case 4:
			{
				cursor();
				break;
			}
			case 5:
			{
				exit(1);
				break;
			}
			default :
			{
				printf("wrong choose");
			}
		}
	}while(wish != 5);
	
}
/*fxn to pop in left stack*/
char popleft()
{
	char give;
	if(lefttop==-1)
	{
		printf("emptystack");
	}
	else
	{
		give=leftstack[lefttop--];
	}
	return give;
}
/*fxn to push in left stack*/
void pushleft(char c)
{
	if(lefttop>MAX)
	{
		printf("overflow");
	}
	else
	{
		leftstack[++lefttop]=c;
	}
}
/*fxn to pop in right stack*/
char popright()
{
	char give;
	if(righttop==-1)
	{
		printf("emptystack");
	}
	else
	{
		give=rightstack[righttop--];
	}
	return give;
}
/*fxn to push in right stack*/
void pushright(char c)
{
	if(righttop>MAX)
	{
		printf("overflow");
	}
	else
	{
		rightstack[++righttop]=c;
	}
}
/*function to display the contant*/
void show()
{
	int i;
	for(i=0;i<=lefttop;i++)
	{
		printf("%c",leftstack[i]);
	}
	for(i=righttop;i>=0;i--)
	{
		printf("%c",rightstack[i]);
	}
	if(lefttop==-1 && righttop!=-1)
	{		
		printf("\nContain Left Stack: empty\tContain Right Stack: %c,%d\n",rightstack[righttop],righttop+1);
	}	
	else if(righttop==-1 && lefttop!=-1)
	{
		printf("\nContain Left Stack: %c,%d\tContain Right Stack: empty\n",leftstack[lefttop],lefttop+1);
	}	
	else if(lefttop!=-1 && righttop!=-1)
	{	
		printf("\nContain Left Stack: %c,%d\tContain Right Stack: %c,%d\n",leftstack[lefttop],lefttop+1,rightstack[righttop],righttop+1);
	}	
	else if(lefttop==-1 && righttop==-1)
	{
		printf("\nContain Left Stack: empty\tContain Right Stack: empty\n");
	}
}
/*fuction to move the cursor*/
void cursor()
{
	int temp;
	printf("move the cursor to ..");
	scanf("%d",&temp);
	if(temp<0||(temp-1)>=(righttop+lefttop+2))
	{
		printf("invalid cursor");
	}
	else if(lefttop>temp-1)
	{
		while(lefttop!=temp-1)	
		{
			pushright(popleft());
		} 
	}
	else if(lefttop<temp-1)
	{
		while(lefttop!=temp-1)	
		{
			pushleft(popright());
		} 
	}
	show();
}
/*del from right*/
void delete()
{
	char temp;
	temp=popright();
	show();
}
/*del from left*/
void backspace()
{	
	char temp;
	temp=popleft();
	show();

}
/*function to insert word*/
void insert()
{
	char string[100];
	int length,i;	
	//printf("enter the word...");
	scanf("%[^\n]",string);
	length=strlen(string);
	for(i=0;i<length;i++)
	{
		pushleft(string[i]);
	}
	show();
}

