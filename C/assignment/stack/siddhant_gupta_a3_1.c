#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
struct mystack 
{
	int top;
	char infix[100],postfix[100],stack[100],prefix[100],stack1[100][100];
}s;
struct postfix1
{
	char stack[MAX][MAX], target[MAX] ;
	char temp1[2], temp2[2] ;
	char str1[MAX], str2[MAX], str3[MAX] ;
	int i, top ;
} ;
char *reverse(char ch[])
{
	int i,j=0;
	char temp;
	i = 0;
	j = strlen(ch) - 1;
	
	while (i < j) 
	{			
		temp = ch[i];
		ch[i] = ch[j];
		ch[j] = temp;
		i++;
		j--;
	}
return ch;
}
void initfix ( struct postfix1 *p )
{
	p -> i = 0 ;
	p -> top = -1 ;
	strcpy ( p -> target, "" ) ;
}
/* copies given expression to target string */
void setexpr ( struct postfix1 *p, char *c )
{
	strcpy ( p -> target, c ) ;
}
/* adds an expr. to the stack */
void push1 ( struct postfix1 *p, char *str )
{
	if ( p -> top == MAX - 1 )
		printf ( "\nStack is full." ) ;
	else
	{
		p -> top++ ;
		strcpy ( p -> stack[p -> top], str ) ;
	}
}
/* pops an expr. from the stack */
void pop1( struct postfix1 *p, char *a )
{
	if ( p -> top == -1 )
		printf ( "\nStack  is empty." ) ;
	else
	{
		strcpy ( a, p -> stack[p -> top] ) ;
		p -> top-- ;
	}
}
/* converts given expr. to infix form */
void convert ( struct postfix1 *p )
{
	while ( p -> target[p -> i] )
	{
		/* skip whitespace, if any */
		if( p -> target[p -> i] == ' ' )
			p -> i++ ;
		if ( p -> target[p -> i] == '%' || p -> target[p -> i] == '*' || p -> target[p -> i] == '-' || p -> target[p -> i] == '+' ||p -> target[p -> i] == '/' || p -> target[p -> i] == '$' )
		{
			pop1 ( p, p -> str2 ) ;
			pop1 ( p, p -> str3 ) ;
			p -> temp1[0] = p -> target[p -> i] ;
			p -> temp1[1] = '\0' ;
			strcpy ( p -> str1, p -> str3 ) ;
			strcat ( p -> str1, p -> temp1 ) ;
			strcat ( p -> str1, p -> str2 ) ;
			push1 ( p, p -> str1 ) ;
		}
		else
		{
			p -> temp1[0] = p -> target[p -> i] ;
			p -> temp1[1] = '\0' ;
			strcpy ( p -> temp2, p -> temp1 ) ;
			push1 ( p, p -> temp2 ) ;
		}
		p -> i++ ;
	}
}
void convert1 ( struct postfix1 *p )
{
	while ( p -> target[p -> i] != '\0' )
	{
		/* skip whitespace, if any */
		if ( p -> target[p -> i] == ' ')
		{			
			p -> i++ ;
		}		
		if( p -> target[p -> i] == '%' || p -> target[p -> i] == '*' ||p -> target[p -> i] == '-' || p -> target[p -> i] == '+' ||p -> target[p -> i] == '/' || p -> target[p -> i] == '$' )
		{
			pop1 ( p, p -> str2 ) ;
			pop1 ( p, p -> str3 ) ;
			p -> temp1[0] = p -> target[ p -> i] ;
			p -> temp1[1] = '\0' ;
			strcpy ( p -> str1, p -> temp1 ) ;
			strcat ( p -> str1, p -> str3 ) ;
			strcat ( p -> str1, p -> str2 ) ;
			push1 ( p, p -> str1 ) ;
		}
		else
		{
			p -> temp1[0] = p -> target[p -> i] ;
			p -> temp1[1] = '\0' ;
			strcpy ( p -> temp2, p -> temp1 ) ;
			push1 ( p, p -> temp2 ) ;
		}
		p -> i++ ;
	}
}
/* displays the expression */
void show1 ( struct postfix1 p )
{
	char *t ;
	strcpy(p.stack[0],reverse(p.stack[0]));
	t = p.stack[0] ;
	while ( *t )
	{
		printf ( "%c ", *t ) ;
		t++ ;
	}
}
/*display fuction*/
void show ( struct postfix1 p )
{
	char *t ;
	t = p.stack[0] ;
	while ( *t )
	{
		printf ( "%c ", *t ) ;
		t++ ;
	}
}
/*pop fuction*/
char pop()
{
 	char item; 
 	if(s.top <= -1)
 	{
  		printf("\nStack Underflow. Pop not possible.\n");
 	}
 	else
 	{
	  	item = s.stack[s.top];
	  	s.stack[s.top] = 0;
	  	s.top = s.top-1;
	}
 	return(item);
}
/*push fuction*/
void push(char item)
{
 	if(s.top >= 99)
 	{
  		printf("\nStack Overflow. Push not possible.\n");
 	}
 	else
 	{
  		s.top = s.top+1;
  		s.stack[s.top] = item;
 	}
}
/*to find is the symbol is operator or not*/
int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
 	{
	  	return 1;
 	}
 	else
	{
		return 0;
	}
}
/*priority of symbol*/
int order(char symbol)
{
	if(symbol == '^')
 	{
  		return(3);
 	}
 	else if(symbol == '*' || symbol == '/')
 	{
  		return(2);
 	}
 	else if(symbol == '+' || symbol == '-')
 	{
  		return(1);
 	}
 	else
 	{
 		return(0);
 	}
}
/*infix to postfix*/
void in_post()
{
	int i=0,j=0;
	char item,x;
	i=0;
 	j=0;
 	item=s.infix[i++];
 	while(item != '\0')
 	{
 		if(item == '(')
  		{
   			push(item);
		}
		else if((item >= 'A'  && item <= 'Z') || (item >= 'a' && item <= 'z'))
  		{
   			s.postfix[j++] = item;
  		}
  		else if(is_operator(item) == 1)
  		{
   			x=pop();
   			while(is_operator(x) == 1 && order(x)>=order(item))
   			{
    				s.postfix[j++] = x;
    				x = pop();
   			}
   			push(x);
   			push(item);			
  		}
  		else if(item == ')')
  		{
  			x = pop();
   			while(x != '(')
   			{
    				s.postfix[j++] = x;
    				x = pop();
   			}
  		} 
		else
  		{
  	 		printf("\nInvalid Arithmetic Expression.\n");
  	 		exit(0);
  		}
  		item = s.infix[i++];	
	}
		while(s.top>-1)	
		{
                        char item;
			item=pop();
			s.postfix[j++]=item;	
		}
}
/*from infix to prefix*/
void in_pre()
{
	int i=0,j=0;
	char item,x;
	i=0;
 	j=0;
 	item=s.infix[i++];
 	while(item != '\0')
 	{
 		if(item == ')')
  		{
   			push(item);
		}
		else if((item >= 'A'  && item <= 'Z') || (item >= 'a' && item <= 'z'))
  		{
   			s.prefix[j++] = item;
  		}
  		else if(is_operator(item) == 1)
  		{
   			x=pop();
   			while(is_operator(x) == 1 && order(x)>order(item))
   			{
    				s.prefix[j++] = x;
    				x = pop();
							
   			}
   			push(x);
   			push(item);			
  		}
		else if(is_operator(item) == 1)
		{	
			x=pop();
			while(is_operator(x) == 1 && order(x)==order(item))
			{	
				
				//s.prefix[j++] = item;
				push(item);
			}
			push(x);
			push(item);
		}
		
  		else if(item == '(')
  		{
  			x = pop();
   			while(x != '(')
   			{
    				s.prefix[j++] = x;
    				x = pop();
   			}
  		} 
		else
  		{
  	 		printf("\nInvalid Arithmetic Expression.\n");
  	 		exit(0);
  		}
  		item = s.infix[i++];	
	}
		while(s.top>-1)	
		{
                        char item;
			item=pop();
			s.prefix[j++]=item;	
		}
}
/*main content*/
void main()
{
	struct postfix1 q ;
	char expr[MAX] ;
	int choose,choose2;
	printf("In which form do you want to input the expression \n1\tInfix\n2\tPostfix\n3\tPrefix\n")	;
	scanf("%d",&choose2);
	switch(choose2)
	{
		case 1:
		{
			printf("\nEnter the arithmetic expression in Infix notation enclosed in parentheses: \n");
			scanf("%s",s.infix);
			printf("change the expression into \n1 postfix\n2 prefix\n");
			scanf("%d",&choose);	
			switch(choose)
			{
				case 1:
				{	
					in_post();
					printf("%s",s.postfix);
					break;
				}
				case 2:
				{		 
					strcpy(s.infix,reverse(s.infix));
					in_pre();
					strcpy(s.prefix,reverse(s.prefix));
					printf("%s",s.prefix);
					break;
				}
			}
			break;
		}
		case 2:
		{
			initfix ( &q ) ;
			printf ( "\nEnter an expression in postfix form: \n" ) ;
			scanf("%s", expr ) ;
			printf("change the expression into \n1\tInfix\n2\tPrefix\n");
			scanf("%d",&choose);
			switch(choose)	
			{
				case 1:
				{
					setexpr ( &q, expr ) ;
					convert ( &q ) ;
					printf ( "\nThe infix expression is: \n" ) ;
					show ( q ) ;
					break;
				}
				case 2:
				{
					setexpr ( &q, expr ) ;
					convert1 ( &q ) ;
					printf ( "\nThe Prefix expression is: \n" ) ;
					show ( q ) ;
					break;
				}
			}
			break;
		}
		case 3:
		{
			initfix ( &q ) ;
			printf ( "\nEnter an expression in prefix form: \n" ) ;
			scanf("%s", expr ) ;
			printf("change the expression into \n1\tInfix\n2\tPostfix\n");
			scanf("%d",&choose);
			switch(choose)	
			{
				case 1:
				{	
					strcpy(expr,reverse(expr));
					setexpr ( &q, expr ) ;
					convert ( &q ) ;
					printf ( "\nThe infix expression is: \n" ) ;
					show1 ( q ) ;
					break;
				}
				case 2:
				{	
					strcpy(expr,reverse(expr));
					setexpr ( &q, expr ) ;
					convert1 ( &q ) ;
					printf ( "\nThe Postfix expression is: \n" ) ;
					show1 ( q ) ;
					break;
				}
			}
			break;
		}
	}
}
