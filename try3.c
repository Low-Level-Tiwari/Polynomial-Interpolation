#include<math.h>
#include<stdio.h>

#define act(x) (((0.333)*expf(-3*x))+ (0.666667))
#define U(x) ((-3*x) + (2))

void main()
{
	float uk, ukplus1,fk, h, x;
	int k,n;
	k = 0;
	n = 30;
	printf("\nx: ");
	scanf("%f",&x);
	printf("h: ");
	scanf("%f",&h);

	uk = act(x);
	fk = U(uk); 

	printf("\n K    \t  X\t\t  Uk\t\t  Fk \t\t Actual\n");
	printf("-----------------------------------------------------------------------------\n");
	printf(" 0\t%0.6f\t%0-10f\t%0-10f\t%f\n",x,uk,fk,act(x));
	
	while(k < n)
	{
		x = x + h;
		fk = U(uk);
		ukplus1 = uk + h*fk;
		uk = ukplus1;
		k++;
		printf(" %d\t%0.6f\t%0-10f\t%0-10f\t%f\n",k,x,uk,fk,act(x));
	}
}
