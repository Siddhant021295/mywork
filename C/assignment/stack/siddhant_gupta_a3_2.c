#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAX 50

struct fix
{
	int stack[MAX] ;
	int top, nn ;
	char *s ;
} ;
/*to reverse the fxn*/
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
/* initializes data members */
void initpostfix ( struct fix *p )
{
	p -> top = -1 ;
}

/* sets s to point to the given expr. */
void setexpr ( struct fix *p, char *str )
{
	p -> s = str ;
}

/* adds digit to the stack */
void push ( struct fix *p, int item )
{
	if ( p -> top == MAX - 1 )
		printf ( "\nStack is full." ) ;
	else
	{
		p -> top++ ;
		p -> stack[p -> top] = item ;
	}
}

/* pops digit from the stack */
int pop ( struct fix *p )
{
	int data ;

	if ( p -> top == -1 )
	{
		printf ( "\nStack is empty." ) ;
			return 0 ;
	}

	data = p -> stack[p -> top] ;
	p -> top-- ;

	return data ;
}

/* evaluates the postfix expression */
void calculate( struct fix *p )
{
	int n1, n2, n3 ;
	while ( *( p -> s ) )
	{
		/* skip whitespace, if any */
		if ( *( p -> s ) == ' ' || *( p -> s ) == '\t' )
		{
			p -> s++ ;
			continue ;
		}

		/* if digit is encountered */
		if ( isdigit ( *( p -> s ) ) )
		{
			p -> nn = *( p -> s ) - '0' ;
			push ( p, p -> nn ) ;
		}
		else
		{
			/* if operator is encountered */
			n1 = pop ( p ) ;
			n2 = pop ( p ) ;
			switch ( *( p -> s ) )
			{
				case '+' :
					  n3 = n2 + n1 ;
					  break ;

				case '-' :
					  n3 = n2 - n1 ;
					  break ;

				case '/' :
					  n3 = n2 / n1 ;
					  break ;

				case '*' :
					  n3 = n2 * n1 ;
					  break ;

				case '%' :
					  n3 = n2 % n1 ;
					  break ;
				default :
					  printf ( "Unknown operator" ) ;
					  exit ( 1 ) ;
			}

			push ( p, n3 ) ;
		}
		p -> s++ ;
	}
}
/*function to calculate the expression*/
void calculate1( struct fix *p )
{
	int n1, n2, n3 ;
	while ( *( p -> s ) )
	{
		/* skip whitespace, if any */
		if ( *( p -> s ) == ' ' || *( p -> s ) == '\t' )
		{
			p -> s++ ;
			continue ;
		}

		/* if digit is encountered */
		if ( isdigit ( *( p -> s ) ) )
		{
			p -> nn = *( p -> s ) - '0' ;
			push ( p, p -> nn ) ;
		}
		else
		{
			/* if operator is encountered */
			n1 = pop ( p ) ;
			n2 = pop ( p ) ;
			switch ( *( p -> s ) )
			{
				case '+' :
					  n3 = n1 + n2 ;
					  break ;

				case '-' :
					  n3 = n1 - n2 ;
					  break ;

				case '/' :
					  n3 = n1 / n2 ;
					  break ;

				case '*' :
					  n3 = n1 * n2 ;
					  break ;

				case '%' :
					  n3 = n2 % n1 ;
					  break ;
				default :
					  printf ( "Unknown operator" ) ;
					  exit ( 1 ) ;
			}

			push ( p, n3 ) ;
		}
		p -> s++ ;
	}
}
/*display fuction*/
void show ( struct fix p )
{
	p.nn = pop ( &p ) ;
	printf ( "Result is: %d", p.nn ) ;
}
void main( )
{
	int choose;
	struct fix q ;
	char expr[MAX] ;
	initpostfix ( &q ) ;
	printf("what type of expression will you enter\n1\tPostfix\n2\tPrefix\n");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
		{	
			printf("enter the Postfix expression\n");
			scanf ("%s",expr) ;
			setexpr ( &q, expr ) ;
			calculate ( &q ) ;
			show ( q ) ;
			break;
		}
		case 2:
		{
			printf("enter the Prefix expression\n");
			scanf ("%s",expr) ;
			strcpy(expr,reverse(expr));
			setexpr ( &q, expr ) ;
			calculate1 ( &q ) ;
			show ( q ) ;
			break;		
		}
		default :
		{
			printf("\nworng choose...\n");
		}
	}
}

