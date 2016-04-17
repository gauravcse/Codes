#include<stdio.h>
#include<math.h>
int main()  {
	int t;
	scanf("%d",&t);
	while(t--) {
		double a,b,c,d;
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		printf("\n");
		double semi=(a+b+c+d)*0.5;
	//	printf("%f\n",semi);
		double ans=pow(((semi-a)*(semi-b)*(semi-c)*(semi-d)),0.5);
		printf("%lf\n",ans);
		
	}
}
