#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *t1;
	float x[4][2],y[4][2],s[3][3],a[3][3],b[2],c[3],d[3];int t,i,j,z;
	t1=fopen("triangle.txt","r");
	for(j=0;j<2;j++)
	{
		printf("the vertex of tringle %d",j+1);
		for(i=0;i<3;i++)
		{	
			fscanf(t1,"(%f,%f)\n",&x[i][j],&y[i][j]);
			printf("(%.1f,%.1f)\t",x[i][j],y[i][j]);
		}
		printf("\n");
	}
fclose(t1);
x[3][0]=x[0][0]; x[3][0]=x[0][1]; y[3][0]=y[0][0]; y[3][1]=y[0][1];
for(j=0;j<2;j++)
{
	b[j]=((x[1][j]*y[2][j]+x[2][j]*y[0][j]+x[0][j]*y[1][j]-x[2][j]*y[1][j]-x[0][j]*y[2][j]-x[1][j]*y[0][j])/2);
	b[j]<0?b[j]=(-b[j]):(b[j]=b[j]);
//	printf("%.2f\n",b[j]);
}
if(b[0]==0.0||b[1]==0.0)
{
	printf("one or both are not triangles");
	exit(1);
}

	//area of tringle1 with a point of other triangle 
 	for(t=0;t<3;t++)
	{
		for(i=0;i<3;i++)
		{
				a[i][t]=(x[i][0]*y[i+1][0]+x[t][1]*y[i][0]+x[i+1][0]*y[t][1]-x[t][1]*y[i+1][0]-x[i][0]*y[t][1]-x[i+1][0]*y[i][0])/2;
				if(a[i][t]<0)
				{
				a[i][t]=-a[i][t];
				}
		}c[t]= a[0][t]+a[1][t]+a[2][t];
	}
	//area of triangle2 with a point of other triangle
	for(t=0;t<3;t++)
	{
		for(i=0;i<3;i++)
		{
			s[i][t]=(x[i][1]*y[i+1][1]+x[t][0]*y[i][1]+x[i+1][1]*y[t][0]-x[t][0]*y[i+1][1]-x[i][1]*y[t][0]-x[i+1][1]*y[i][1])/2;
			if(s[i][t]<0.0)
			{
				s[i][t]=-s[i][t];
			}
		}d[t]= s[0][t]+s[1][t]+s[2][t];
	}
	
	if(b[0]==c[0]||b[0]==c[1]||b[0]==c[2]||b[1]==d[0]||b[1]==d[1]||b[1]==d[2])
	{
		printf("the tringle have atleast one point in common");
	}
	else
	{
		printf("no points in common");
	}
	}
