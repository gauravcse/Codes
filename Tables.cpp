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

int cmpfnc(const void* a,const void* b){
	return (*(int*)b-*(int*)a);
}

int main(void) {
	int n,k,s;
	scanf("%d %d %d",&n,&k,&s);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	qsort(arr,n,sizeof(int),cmpfnc);
	int total=k*s;
	int i=0;
	while(arr[i]<total) {
		total-=arr[i];
		i++;
	}
	printf("%d\n",++i);
}
