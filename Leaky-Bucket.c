#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x

void main()
{
	int cap,o_rate,packets[20]={0},i=0,c,time,re=0,dr,x;
	
	printf("Enter Bucket size : ");
	scanf("%d",&cap);
	printf("Enter Output rate : ");
	scanf("%d",&o_rate);
	
	do
	{
		printf("\nEnter packets received at time %d-sec : ",i+1);
		scanf("%d",&packets[i]);
		i++;
		printf("Enter 1 to continue or 0 to exit : ");
		scanf("%d",&c);
	}while(c);
	time = i;
	
	printf("\n\nTime \tReceived \tSent \tDropped \tRemained\n");
	
	for(i=0;re||i<time;i++)
	{
		printf("%d ",i+1);
		printf("\t%d ",packets[i]);
		printf("\t%d ",MIN((packets[i]+re),o_rate));
		
		x = packets[i]+re-o_rate;
		if(x>0)
		{
			if(x>cap)
			{
				dr = x - cap;
				re = cap;
			}
			else
			{
				dr = 0;
				re = x;
			}
		}
		else
		{
			dr = 0;
			re = 0;
		}
		printf("\t%d ",dr);
		printf("\t%d\n",re);
	}
}
