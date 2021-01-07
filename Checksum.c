#include<stdio.h>
#include<string.h>

int checksum(int f)
{
	char s[100];
	int sum=0,i,n,temp;

	scanf("%s",s);
	
	if(strlen(s)%2!=0)
		n = (strlen(s)+1)/2;
	else
		n = (strlen(s))/2;
		
	for(i=0;i<n;i++)
	{
		temp = s[i*2];
		temp = temp*256 + s[(i*2)+1];
		sum = sum + temp;
	}
	
	if(f==1)
	{
		printf("Enter CheckSum : ");
		scanf("%x",&temp);
		sum = sum + temp;
	}
	
	if(sum%65536!=0)
	{
		n = sum%65536;
		sum = (sum/65536)+n;
	}
	sum = 65536-sum;
	
	return sum;
}

void main()
{
	int c,sum;
	printf("1-Encode\n2-Decode\n3-Exit\n");
	
	do
	{
		printf("Enter your choice : ");
		scanf("%d",&c);
		
		switch(c)
		{
			case 1:
				printf("Enter the string : ");
				sum = checksum(0);
				printf("CheckSum to be appended is : %x\n",sum);
				break;
			case 2:
				printf("Enter the string : ");
				sum = checksum(1);
				if(sum!=0)
					printf("CheckSum entered is invalid or data is tampered\n");
				else
					printf("CheckSum is valid\n");
				break;
			case 3:
				break;
			default:
				printf("Enter a correct choice\n");
		}
	}while(c!=3);
}
