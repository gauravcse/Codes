#include<stdio.h>
#include<math.h>
int main()  {
	int n;
	scanf("%d",&n);
	printf("\n");
	while(n)  {
		int sum=0;
		int count;
		for(count=0;count<n;count++) {
			sum+=pow((n-count),2);
		}
	    printf("%d\n",sum);
	    scanf("%d",&n);
	}
}
