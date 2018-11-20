#include<stdio.h>
main()
{
	int a[100000];long int v=0;
	int t,j;
	FILE *c;
	printf("welcome to the program\n\n\n");
	c=fopen("integer.txt","r");
	for(t=0;t<100000;t++)
	{
			fscanf(c,"%d",&a[t]);
	}
	fclose(c);	
	for(t=0;t<100000;t++)/*is no a multiple of 11*/
		{
			if((a[t]%11)==0)
			v++;
		}
	printf("the no of numbers multiples of 11 are %ld\n",v);
	v=0;
	for(t=0;t<100000;t++)/*is no is multiple of 9*/
		{	
			if((a[t]%9)==0)
			v++;
		}
	printf("the no of numbers multiples of 9 are %ld\n",v);
	v=0;
	for(t=0;t<100000;t++)/*no of element in right place*/
		if(a[t]==(t+1))
		v++;
	printf("no of letters in the right place %ld \n",v);
	v=0;
	for(t=0;t<100000;t++)/*no of inversion*/
	{
	if(a[t]>a[t+1])
	v++;
    }
	printf("total no of inversion are %ld\n",v);
	}
