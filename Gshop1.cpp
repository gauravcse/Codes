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
		if(n==0) {
			printf("%d\n",0);
			continue;
		}
		int arr[n];
		LOOP {
			scanf("%d",&arr[i]);
		}
		qsort(arr,n,sizeof(int),cmpfnc);
		int count=0;
		while(k>0) {
			if(arr[count]>0)
				break;
			arr[count]=-arr[count];
			count++;
			k--;
		}
		qsort(arr,n,sizeof(int),cmpfnc);
		if(k>0 && (k%2!=0))
			arr[0]=-arr[0];
		LLU sum=0;
		LOOP{
			sum+=arr[i];
		}
		printf("%llu",sum);
	}	
	
}

