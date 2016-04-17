#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#define LOOP for(int i=1;i<=y;i++)
#define TEST while(t--)
#define T int t
#define TD scanf("%d",&t)
#define N int n
#define ND scanf("%d",&n)
#define LLU long long unsigned

int main(void) {
	T;
	TD;
	N;
	ND;
	TEST {
		long long int x,y;
		scanf("%lld %lld",&x,&y);
		long long int rem=1;
		LOOP{
			rem=(rem*x)%n;
		}
		printf("%lld\n",rem);
	}
	
}
