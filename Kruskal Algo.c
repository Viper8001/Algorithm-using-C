#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[10][10],par[10];
int find(int);
int uni(int,int);
int main()
{
printf("Kruskall Algorithm....\n");
printf("Enter the number of vertices:\n");
scanf("%d",&n);
printf("Enter the adjacency matrices:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if (cost[i][j]==0)
cost[i][j]=999;
}
}
printf("\n The edges of minimum spanning tree:\n");
while(ne<n)
{
for(i=1,min=999;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if (cost[i][j]<min)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
}
}
u=find(u);
v=find(v);
if(uni(u,v))
{
    printf("%d edges(%d%d)=%d\n",ne++,a,b,min);
    mincost+=min;
}
cost[a][b]=cost[b][a]=999;
}
printf("\n Minimum cost=%d\n",mincost);
getch();
return 0;
}
int find(int i)
{
	while(par[i])
	i=par[i];
	return i;
}
int uni(int i,int j)
{
if(i!=j)
{
par[j]=i;
return 1;
}
return 0;
}
