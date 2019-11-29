#include <stdio.h>
int p[5];
int m[5][5];
void MCM(int);
int min(int,int);
int main()
{
int n,i,j;
printf("Enter the no of matrices to multiply \n");
scanf("%d",&n);
printf("Enter the dimention array p: \n");
for(i=0;i<=n;i++)
scanf("%d",&p[i]);
MCM(n);

printf("\n Minimum cost of multiplication of all matrices are:%d",m[1][4]);
return 0;
}

void MCM(int n)
{
int i,j,k,x;
for(i=1;i<=n;i++)
m[i][i]=0;
x=2;
for(i=1;i<=n-1;i++)
{
j=x;
while(j<=n)
{
m[i][j]=1000 ;
j++;
}
x++;
}

x=2;
while(x<=n)
{
i=1;
j=x;
while(i<=n)
{
if(j<=n)
{
for(k=i;k<=j-1;k++)
{
m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
}
j++;
}
i++;
}
x++;
}
}
int min(int a,int b)
{
if(a<b)
return a;
else
return b;
}