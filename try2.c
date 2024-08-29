#include<math.h>
#include<stdio.h>

#define act(x) (((1.0/3)*exp(-3*x))+(2.0/3))
#define U(x) ((-3*x) + (2))

void main()
{
	double uk, ukplus1,fk,fkm1,h,hm,x;
	int k,n;
	k = 0;
	n = 30;
	printf("\nx: ");
	scanf("%lf",&x);
	printf("h: ");
	scanf("%lf",&h);

	uk = act((x));
	fkm1 = ((-3*uk) + (2));

	printf("\n K    \t  X\t\t  Uk\t\t  Fk \t\t Actual\n");
	printf("-----------------------------------------------------------------------------\n");
	printf(" 0\t%0.6f\t%0-10f\t%0-10f\t%f\n",x,uk,fkm1,act(x));
	uk = act((x+h));
	fk = ((-3*uk) + (2));
	printf(" 1\t%0.6f\t%0-10f\t%0-10f\t%f\n",x+h,uk,fk,act((x+h)));

	hm=h/2;
	x = x + h;
	k += 1;

	while(k < n)
	{
		x = x + h;
		ukplus1 = uk + hm*(3*fk - fkm1);
		uk = ukplus1;
		k++;
		printf(" %d\t%0.6f\t%0-10f\t%0-10f\t%f\n",k,x,ukplus1,fk,act(x));
		fkm1 = fk;
		fk = ((-3*uk) + (2));
	}
}
