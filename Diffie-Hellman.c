#include<stdio.h>

int compute(int m, int n, int p)
{
	int r,y=1;
	
	while(n>0)
	{
		r = n%2;
		if(r==1)
			y = (y*m)%p;
		
		m = (m*m)%p;
		n = n/2;
	}
	
	return y;
}

void main()
{
	int a,b,A,B;
	int g=5,p=23;
	
	a = 6;
	b = 15;
	
	A = compute(g,a,p);
	B = compute(g,b,p);
	printf("Alice's Public Key : %d\n",A);
	printf("Bob's Public Key : %d\n",B);
	
	int aKey = compute(B,a,p);
	int bKey = compute(A,b,p);
	printf("Alice's Secret Key : %d\n",aKey);
	printf("Bob's Secret Key : %d\n",bKey);
	
}
