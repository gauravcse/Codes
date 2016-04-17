#include<stdio.h>	
#include<math.h>
int main()  {
	int t;
	scanf("%d",&t);
	while(t--)  {
	double digit=0;
	long long unsigned n;
	scanf("%llu",&n);
	long long unsigned i;
	for(i=1;i<=n;i++) {
		double j=i;
		digit+=log10(j);
	}
	if(n>1) {
    	long int dig=ceil(digit);
    	printf("%ld\n",dig);
    }
    else
        printf("1\n");
    }
}


