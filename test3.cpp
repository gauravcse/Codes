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
	int p[3][5] = {
{ 2, 8, 6, 8, 10},
{ 3, 6, 9, 12, 15},
{ 5, 10, 15, 20, 25}
};

 printf("%d	%d	%d	%d	%d",*(*p), *(*p+1), *(*(p+1)),
*(*(p+1)+1), *(*(p+1)+1)+1);
	
}
