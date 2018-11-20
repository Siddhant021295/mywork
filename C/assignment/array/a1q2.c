#include<stdio.h>
#include<stdlib.h>
main()
{
	FILE *t1;
	float x[4][2],y[4][2],a[3][2],b[2];
	int t,i,j,z;
	t1=fopen("triangle.txt","r");
	printf("welcome to the program\n");
	for(j=0;j<2;j++)/*scanfing from file*/
	{
		printf("the vertex of tringle %d",j+1);
		for(i=0;i<3;i++)
		{	
			fscanf(t1,"(%f,%f)\n",&x[i][j],&y[i][j]);
			printf("(%f,%f)\t",x[i][j],y[i][j]);
		}
		printf("\n");
	}
fclose(t1);
x[3][0]=x[0][0]; x[3][1]=x[0][1]; y[3][0]=y[0][0]; y[3][1]=y[0][1];
/*area of the triangle*/
for(j=0;j<2;j++)
{
	b[j]=(x[1][j]*y[2][j]+x[2][j]*y[0][j]+x[0][j]*y[1][j]-x[2][j]*y[1][j]-x[0][j]*y[2][j]-x[1][j]*y[0][j])/2;
}
/*if(b[1]==0||b[2]==0.0)
{
	printf("\none or both are not triangles");
	exit(1);
}*/

for(j=0;j<2;j++)
{
	for(i=0;i<3;i++)
	{
		a[i][j]=((x[i][j]-x[i+1][j])*(x[i][j]-x[i+1][j]))+((y[i][j]-y[i+1][j])*(y[i][j]-y[i+1][j]));
	}
}
	for(j=0;j<2;j++)
	{
		for(z=0;z<3;z++)
		{
			for(i=0;i<3;i++)
			{		
				if(a[i][j]>a[z][j])
				{
					t=a[z][j];
					a[z][j]=a[i][j];
					a[i][j]=t;		
				}
			}
		}	
	}
if((a[0][0]==a[0][1])&&(a[1][0]==a[1][1])&&(a[2][0]==a[2][1]))
{
printf("tringles are congruent");
}
else
printf("no good ");
}

