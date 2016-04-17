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
		char *a,*b;
		scanf("%s %s",a,b);
		int l=strlen(a)>=strlen(b)?strlen(a):strlen(b);
		int arr[l+5][l+5];
		for(int i=0;i<=l;i++) {
			for(int j=0;j<=l;j++) {
				arr[i][j]=0;
			}
		}
		for(int i=0;i<=l;i++) {
			arr[i][0]=i;
			arr[0][i]=i;
		}
		for(int i=0;i<=l;i++) {
			for(int j=0;j<=l;j++) {
				printf("%d	",arr[i][j]);
			}
			printf("\n");
		}
	}
	
}
