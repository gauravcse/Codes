#include<stdio.h>
#include<math.h>
int main()  {
	int t;
	scanf("%d",&t);
	printf("\n");
	while(t) {
		long int s;
		scanf("%l",&s);
		double d=(1-(3/(2*sqrt(s))));
		printf("%0.6f\n",d);
		t--;
	}
}
