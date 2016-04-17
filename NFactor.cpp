#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int primecheck(int n);
int factorful[1000007];
int prime[175];
int count=0;

void primes() {
	prime[0]=2;
	prime[1]=3;
	count=2;
	for(int i=5;i<=1000;i+=2){
		if(primecheck(i))
			prime[count++]=i;
	}
}

int primecheck(int n){
	int s=sqrt(n)+1;
	for(int i=2;i<=s;i++) {
		if(n%i==0)
			return 0;
	}
	return 1;
}

int checkFactors(int n) {
	int fac=0;
	int i=0;
	while(i<count && n>prime[i]) {
		if(n%prime[i]==0) {
			fac++;
			n/=prime[i];
			while(n%prime[i]==0)
				n/=prime[i];
		}
		i++;
	}
	if(n==1)
		return fac;
	else
		return ++fac;
}



int main(void) {
	primes();
	//for(int i=0;i<count;i++)
	//	printf("%d	",prime[i]);
	int t;
	scanf("%d",&t);
	while(t--) {
		int a,b,n;
		scanf("%d %d %d",&a,&b,&n);
		if(n==0) {
			printf("1\n");
			continue;
		}
		int answer=0;
		for(int i=a;i<=b;i++) {
			if(i==1) {
				factorful[1]=0;
				continue;
			}
			if(factorful[i]==0) {
				int check=checkFactors(i);
				factorful[i]=check;
			}
			if(factorful[i]==n)
				answer++;
		}
		printf("%d\n",answer);
	}
}
