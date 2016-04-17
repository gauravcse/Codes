#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<stdbool.h>
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
		int clone=1;
		int flag=0;
		for(int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
		}
		for(int i=0;i<n-1;i++){
			if(arr[i]>clone) {
				flag=1;
				break;
			}
			else {
				clone-=arr[i];
				clone*=2;
			}
		}
		clone-=arr[n-1];
		if(flag==0 && clone==0) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}	
	
}
