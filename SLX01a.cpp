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

int *arr;
int cmpfnc(const void *a,const void *b) {
	return (*(int*)b-*(int*)a);
}

int main(void) {
	T;
	TD;
	TEST {
		int n,k;
		scanf("%d %d",&n,&k);
		arr=(int*)malloc(sizeof(int)*n);
		LOOP{
			scanf("%d",&arr[i]);
		}
		LLU count=0;
		qsort(arr,n,sizeof(int),cmpfnc);
		/*count+=arr[0];
		k--;*/
		if(n==1) {
			count=arr[0]*k;
			printf("%llu\n",count);
			continue;
		}
		while(k>0) {
			while(arr[0]>=arr[1] && k>0) {
				k--;
				count+=arr[0];
				arr[0]--;
			}
			if(arr[0]<arr[1])
				qsort(arr,n,sizeof(int),cmpfnc);
			
		}
		printf("%llu\n",count);
	}
	
}
