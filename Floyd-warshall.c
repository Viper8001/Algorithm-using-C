#include <stdio.h>
int cost[10][10],A[10][10],n;
int min(int,int);
void all_pair();
int main()
{
int i,j;
printf("Enter the no of vertices\n");
scanf("%d",&n);
printf("Enter the cost matrix\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&cost[i][j]);
all_pair();
printf("The distance of all pairs\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
printf("%d \t", A[i][j]);
return 0;
}
void all_pair()
{
int i,j,k;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
A[i][j]=cost[i][j];
for(k=0;k<n;k++)
for(i=0;i<n;i++)
for(j=0;j<n;j++)
A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
}
int min(int x,int y)
{
if(x<y)
return x;
else
return y;
}
