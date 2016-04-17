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
		while(k>0) {
			int i=0;
			while(i<n-1 && arr[i]<arr[i+1]) {
				if(k<=0)
					break;
				count+=arr[i+1];
				arr[i+1]--;
				i++;
				k--;
				/*for(int j=0;j<n;j++)
					printf("%d    ",arr[j]);
				printf("\n");*/
			}
			if(k<=0)
				break;
			count+=arr[i];
			arr[i]--;
			k--;
		/*	for(int j=0;j<n;j++)
				printf("%d    ",arr[j]);
			printf("\n");*/
		}
		printf("%llu\n",count);
	}
	
}
