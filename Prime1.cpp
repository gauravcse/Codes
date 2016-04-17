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
#define N int n
#define ND scanf("%d",&n)
#define LLU long long unsigned

short *sieve_check;

short *prime_check(short sieve_check[],LLU sieve[],int num,int n) {
	int i;
	int div=sieve[0]/num;
	int lower=num*div;
	if(lower==sieve[0])
		i=0;
	else{
		lower=lower+num;
		i=(lower-sieve[0]);
	}
	while(i<n) {
		sieve_check[i]=1;
		i+=num;
	}
	return sieve_check;
}

int main(void) {
	T;
	TD;
	TEST {
		LLU m,n;
		scanf("%llu %llu",&m,&n);
		LLU sieve[n-m+1];
		sieve_check=(short*)malloc(sizeof(short)*(n-m+1));
		for(int i=0;i<=(n-m+1);i++) {
			sieve[i]=m+i;
			sieve_check[i]=0;
		}
		int i=1;
		sieve_check=prime_check(sieve_check,sieve,2,n-m+1);
		sieve_check=prime_check(sieve_check,sieve,3,n-m+1);
		while(1) {
			int low=(6*i)-1;
			int high=(6*i)+1;
			if(sieve[0]/low==0)
				break;
			sieve_check=prime_check(sieve_check,sieve,low,n-m+1);
			if(sieve[0]/high==0)
				break;
			sieve_check=prime_check(sieve_check,sieve,high,n-m+1);
			i++;
		}
		//for(int i=0;i<=(n-m);i++)
		//	printf("%llu	",sieve[i]);
		for(int i=0;i<=(n-m);i++){
			if(sieve[i]==1)
				continue;
			if(sieve[i]==2 || sieve[i]==3) {
				printf("%d\n",sieve[i]);
				continue;
			};
			if(!sieve_check[i])
				printf("%llu\n",sieve[i]);
		}
		printf("\n");
	}	
	
}
