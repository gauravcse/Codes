#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#define LOOP for(int i=0;i<n;i++)
#define TEST while(t--)
#define T int t
#define TD scanf("%d",&t)
#define N long long unsigned n
#define ND scanf("%llu",&n)
#define LLU long long unsigned

LLU gcd(LLU a,LLU b) {
	if(b==0)
		return a;
	else 
		return gcd(b,a%b);
}

int main(void) {
	T;
	TD;
	TEST {
		N;
		ND;
		LLU p=n/2;
		if(n==1) {
			printf("0\n");
			continue;
		}
		do {
				LLU euclid=gcd(n,p);
				if(euclid==1) {
					printf("%llu\n",p);
					break;
				}
		}while(p--);
		
	}
	
}
