#include<stdio.h>

void main()
{
	int l,a,b,c,d,e,f,g=0,t=0,j=0,i=0;
	float h;
	do
	{
		printf("give the 1st numbers\n");
		scanf("%d %d",&a,&b);
		printf("%d/%d\n",a,b);
		printf("give the 2st numbers\n");
		scanf("%d %d",&c,&d);
		printf("%d/%d\n",c,d);
		printf("operation \n1 for division\n2 for multiplication\n3 for addition\n4 for subtrations\n");
		scanf("%d",&e);
		switch(e)
		{
			case 1:/*division*/
			{
				f=a*d;
				g=b*c;
				h=((float)f/(float)g);break;
			}
			case 2:/*multiplication*/
			{
				f=a*c;
				g=b*d;
				h=((float)f/(float)g);break;
			}
			case 3:/*addition*/
			{
				f=((a*d)+(c*b));
				g=b*d;
				h=((float)f/(float)g);break;
			}
			case 4:/*subtration*/
			{
				f=((a*d)-(c*b));
				g=b*d;
				h=((float)f/(float)g);break;
			}
			default:
			{
			printf("wrong choose\n");
			}
		}
	if(e==1||e==2||e==3||e==4)
	{
		j=f;
		i=g;
		while (j != 0) 
		{
	    t = j;
	    j = i % j;
	    i = t;
	    }
	    f=f/t;
	    g=g/t;
		
			printf("the result in p by q formate is %d/%d and in fraction is %f",f,g,h);
	}
		else
		{
		printf("run again\n");
		}
		printf("\nto run again press '1'\n any key to exit\n");
		scanf("%d",&l);}
	while(l==1);


	
}
