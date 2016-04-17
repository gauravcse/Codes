#include<stdio.h>
#include<math.h>
int main()  {
	long long unsigned n;
	scanf("%llu",&n);
	int t;
	if((n>=2)&&(n<=2,147,483,647)) {
		int t=0;
		long long unsigned num=n;
		long long unsigned sum=0;
		while(1) {
			while(n>0)  {
				sum+=pow((n%10),2);
				num/=10;
				
			}
		t++;
		if(sum>9) {
			n=sum;
			continue;
		}
		 
		else if(sum==1) {
		
		   printf("%d",&t);
		   break;
	}
	
		else {
		}
		   printf("-1");
		   break;
			
			}
		}
		
	}

