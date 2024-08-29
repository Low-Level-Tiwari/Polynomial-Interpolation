#include<math.h>
#include<stdio.h>

#define act(x) (((0.333)*expf(-3*x))+ (0.666667))
#define U(x) ((-3*x) + (2))

void main()
{
	float uk, ukplus1, ukminus1, fk, h, x;
	int k,n;
	k = 0;
	n = 1500;
	printf("\nx: ");
	scanf("%f",&x);
	printf("h: ");
	scanf("%f",&h);

	ukminus1 = act(x);
	uk = act((x+h));
	x = x + h;
	k += 1;
	printf("\n K    \t  X\t\t  Uk\t\t  Fk \t\t Actual\n");
	printf("-----------------------------------------------------------------------------\n");
	printf(" 0\t%0.6f\t%0-10f\t%0-10f\t%f\n",x,ukminus1,U(x),act(x));
	printf(" 1\t%0.6f\t%0-10f\t%0-10f\t%f\n",x+h,uk,U((x+h)),act((x+h)));
	
	while(k < n)
	{
		x = x + h;
		fk = U(uk);
		ukplus1 = ukminus1 + 2*h*fk;
		ukminus1 = uk;
		uk = ukplus1;
		k++;
		printf(" %d\t%0.6f\t%0-10f\t%0-10f\t%f\n",k,x,ukplus1,fk,act(x));
	}
}
