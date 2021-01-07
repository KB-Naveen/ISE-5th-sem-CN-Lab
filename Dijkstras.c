#include<stdio.h>
#define INF 999

void dijk(int n, int s, int cm[10][10], int d[])
{
	int i,j,c,u,f[10],min=100;
	
	for(i=1;i<=n;i++)
	{
		d[i] = cm[s][i];
		f[i] = 0;
	}
	
	c = 2;
	while(c<=n)
	{
		for(j=1;j<=n;j++)
			if(d[j]<min && !f[j])
			{
				min = d[j];
				u = j;
			}
		f[u] = 1;
		c++;
		
		for(j=1;j<=n;j++)
			if(d[u]+cm[u][j]<d[j] && !f[j])
				d[j] = d[u]+cm[u][j];
	}
}

void main()
{
	int n,i,j,cm[10][10],s,d[10];
	
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	
	printf("Enter Cost Matrix :\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cm[i][j]);
			if(cm[i][j]==0)
				cm[i][j] = INF;
		}
	
	printf("Enter source node : ");
	scanf("%d",&s);
	
	dijk(n,s,cm,d);
	
	for(i=1;i<=n;i++)
		if(i!=s)
			printf("From node %d to %d distance is %d\n",s,i,d[i]);
}
