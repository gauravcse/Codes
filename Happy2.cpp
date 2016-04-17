#include<stdio.h>
#include<math.h>
int main()  {
	long long unsinged n;
	scanf("%llu",&n);
	int t;
	if((n>=2)&&(n<=2,147,483,647)) {
		int t=0;
		long long unsinged num=n;
		long long unsinged sum=0;
		while(1) {
			while(num!=0)  {
				sum+=pow((num%10),2);
				num/=10;
				
			}
		t++;
		if(sum>9) {
			num=sum;
			continue;
		}
		 
		else if(sum==1) {
		
		   printf("%d",&t);
		   break;
	}
	
		else {
		   printf("-1");
		   break;
			
			}
		}
		
	}
