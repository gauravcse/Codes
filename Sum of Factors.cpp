#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void) {
	long long unsigned t;
	scanf("%llu",&t);
	while(t--) {
		int num;
		scanf("%d",&num);
		int sum=0;
//		long unsigned num1=sqrt(num);
        int i;
		for(i=2;(i*i)<=num;i++) {
		if(num%i==0)
		  sum+=i+(num/i);
		}
		i--;
		if(i*i==num)
		  sum=sum-i;
		sum=sum+1;
		printf("%d\n",sum);
		
	}
}
