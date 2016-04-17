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

int main(void) {
	T;
	TD;
	TEST {
		N;
		ND;
		int arr[n];
		LOOP {
			scanf("%d",&arr[i]);
		}
		LLU answer=0;
		int count=0;
			while(count<n) {
				LLU num=1;
				while(count<(n-1) && arr[count]<=arr[count+1]) {
					count++;
					num++;
				}
				answer+=(num+(num*num))/2;
				count++;
			}
			printf("%llu\n",answer);
	}
	
}
