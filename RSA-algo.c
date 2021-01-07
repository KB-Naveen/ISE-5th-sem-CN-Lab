#include<stdio.h>
#include<math.h>

int gcd(int a, int b)
{
	int temp;
	while(1)
	{
		temp = a%b;
		if(temp==0)
			return b;
		a = b;
		b = temp;
	}
}

void main()
{
	int p=7,q=3,val;
	double n = p*q;
	double t = (p-1)*(q-1);
	
	double e=2;
	while(e<t)
	{
		val = gcd(e,t);
		if(val==1)
			break;
		else
			e++;
	}
	
	double d,k=2;
	d = (1+(k*t))/e;
	
	double msg = 12;
	double c = fmod(pow(msg,e),n);
	double m = fmod(pow(c,d),n);
	
	printf("Message Sent : %lf\n",msg);
	printf("First prime : %d\n",p);
	printf("Second prime : %d\n",q);
	printf("N value : %lf\n",n);
	printf("Totient : %lf\n",t);
	printf("Encryption key : %lf\n",e);
	printf("Decryption key : %lf\n",d);
	printf("Encrypted data : %lf\n",c);
	printf("Decrypted data : %lf\n",m);
}
