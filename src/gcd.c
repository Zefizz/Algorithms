#include <stdio.h>

/*gcd algorithm*/
int gcd(int a, int b)
{
	if(a<b) {	//swap	
		int tmp = a;
		a = b;
		b = tmp;
	}
	while(b!=0) {
		int tmp = a;
		a = b;
		b = tmp%b;
	}
	return a;
}

int main()
{
	unsigned int a, b;
	printf("a\t"); scanf("%d",&a);
	printf("b\t"); scanf("%d",&b);
	
	printf("GCD(%d,%d) = %d\n",a,b,gcd(a,b));
	
	return 0;
}
