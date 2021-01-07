#include<stdio.h>

void main()
{
	int w_size,no_frames,frames[30],i;
	
	printf("Enter window size : ");
	scanf("%d",&w_size);
	
	printf("Enter Number of frames to send : ");
	scanf("%d",&no_frames);
	
	printf("Enter %d Frames :\n",no_frames);
	for(i=1;i<=no_frames;i++)
		scanf("%d",&frames[i]);
		
	printf("\n\nSending frames according to 'Go Back & Sliding Window Protocol' ...\n\n");
	
	for(i=1;i<=no_frames;i++)
	{
		if(i%w_size==0)
		{
			printf("%d\n",frames[i]);
			printf("ACK recieved\n");
		}
		else
			printf("%d --> ",frames[i]);
	}
	
	if(no_frames%w_size!=0)
		printf("\nACK recieved\n");
}
