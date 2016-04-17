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

int cmpfnc(const void* a,const void* b) {
	return (*(int*)a-*(int*)b);
}

int main(void) {
	T;
	TD;
	TEST {
		int n,k;
		scanf("%d %d",&n,&k);
		int arr[n];
		LOOP {
			scanf("%d",&arr[i]);
		}
		qsort(arr,n,sizeof(int),cmpfnc);
		int count=0;
		for(int i=1;i<=k;i++) {
			if(arr[count]<0){
				arr[count]=-arr[count];
				qsort(arr,n,sizeof(int),cmpfnc);
			}
			else
				arr[count]=-arr[count];
		}
		LLU sum=0;
		LOOP{
			//printf("%d	",arr[i]);
			sum+=arr[i];
		}
		printf("%llu",sum);
	}	
	
}

