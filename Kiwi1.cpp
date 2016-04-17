#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int primes[60000000];
int count=0;
bool isprime(int n);
void prime_fill() {
	primes[count]=2;
	count++;
	for(int i=3;i<1000000000;i+=2) {
		if(isprime(i)==true) {
			primes[count++]=i;
		}
	}
}

bool isprime(int n) {
	int sq=sqrt(n)+1;
	for(int i=2;i<=sq;i++) {
		if(n%i==0)
			return false;
	}
	return true;
}

int factors(long long unsigned n) {
	int sq=sqrt(n)+1;
	int fac=2;;
	for(int i=2;i<=(n/2);i++) {
		if(n%i==0) {
			fac++;
		}

	}
	return fac;
}

bool check(long long unsigned n) {
	int lb=0;
	int ub=count-1;
	while(lb<=ub) {
		int mid=(lb+ub)/2;
		if(primes[mid]==n)
			return true;
		else if(n>primes[mid])
			lb=mid+1;
		else
			ub=mid-1;
	}
	return false;
}

bool sqcheck(long long unsigned n) {
	int sq=sqrt(n);
	if(sq*sq==n)
		return true;
	else
		return false;
}

int main(void) {
	prime_fill();
/*	for(int i=0;i<100;i++) {
		printf("%d	",primes[i]);
	}*/
	int t;
	scanf("%d",&t);
	while(t--) {
		long long unsigned a,b;
		scanf("%llu %llu",&a,&b);
		long long unsigned result=0;
		for(long long unsigned i=a;i<=b;i++) {
			long long unsigned fac=0;
			if(check(i)==true)  {
				result++;
				continue;
//				printf("%lluA	",i);
				//continue;
			};
			if(sqcheck(i)==true) {
				long long unsigned fac=factors(i);
				if(check(fac)==true)
					result++;
				
			}
			/*fac=factors(i);
			bool ans=check(fac);
			if(ans==true) {
				//printf("Factors of %llu is %llu\n",i,fac);
				//printf("%ll",i);
				result++;
			}*/
		}
		printf("%llu\n",result);
	}
}
