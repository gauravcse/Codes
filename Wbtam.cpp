#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#define LOOP for(int i=0;i<n;i++)
#define LOOP1 for(int i=0;i<=n;i++)
#define TEST while(t--)
#define T int t
#define TD scanf("%d",&t)
#define N int n
#define ND scanf("%d",&n)
#define LLU long long unsigned

int main(void) {
	T;
	TD;
	TEST {
		int n;
		scanf("%d",&n);
		char wa[n];
		char ca[n];
		for(int i=0;i<n;i++) {
			scanf("%c",&wa[i]);
			
		}
		for(int i=0;i<n;i++) {
			scanf("%c",&ca[i]);
			//printf("loop2%c",wa[i]);
		}
		int correct=0;
		LLU win[n+1];
		LOOP1 {
			scanf("%llu",&win[i]);
		}
		LOOP {
			if(ca[i]==wa[i])
				correct++;
		}
		printf("%lld\n",win[correct]);
	}
	
}
