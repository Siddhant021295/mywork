#include<stdio.h>
main()
{
	float a,b,c,d,g,f;
	int e,l;
	
	do
	{
	printf("please enter the real part of the numbers\n");
	scanf("%f %f",&a,&b);
	printf("please enter the imaginary part of the numbers\n");
	scanf("%f %f",&c,&d);
	printf("the number you have entered are \n%f i%f and \n%f i%f\n",a,c,b,d);
	printf("operation \n1 for division\n2 for multiplication\n3 for addition\n4 for subtrations\n");
	scanf("%d",&e);
	switch(e)
	{
		case 1:/*division*/
			{
				g=(a*b+c*d)/(b*b+d*d);
				f=(b*c-a*d)/(b*b+d*d);
				break;	
			}
		case 2:/*multiplication*/
			{
				g=(a*b-c*d);
				f=(a*d+c*b);
				break;
			}
		case 3:/*addition*/
			{
				g=a+b;
				f=c+d;
				break;
			}
		case 4:/*subtration*/
			{
				g=a-b;
				f=c-d;
				break;
			}	
		default:
		printf("wrong choose\n");	
	}
	if(e==1||e==2||e==3||e==4)
	printf("the result of the operation is %f i%f\n",g,f);
	else
	printf("choose from the given option\n");
	printf("to run again enter '1'\nany key to exit\n");
	scanf("%d",&l);
	}
	while(l==1);
}


