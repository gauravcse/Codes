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

int cmpfunc(const void* a,const void* b) {
   return (*(int*)a-*(int*)b);
}

int bin_search(int arr[],int num,int len) {
	int left=0;
	int right=len-1;
	/*for(int i=0;i<=right;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");*/
	int mid=0;
	while(left<=right) {
		mid=(left+right)/2;
		if(arr[mid]>num) 
			right=mid-1;
		else if(arr[mid]<num)
			left=mid+1;
		else
			return mid;
	}
	return -1;
	
}

int main(void) {
	T;
	TD;
	TEST {
		N;
		ND;
		LLU answer=0;
		int arr[n];
		int boolean[n];
		LOOP {
			boolean[i]=1;
		}
		LOOP {
			scanf("%d",&arr[i]);
		}
		qsort(arr,n,sizeof(int),cmpfunc);
		LOOP {
			if(boolean[i]==0)
				continue;
			int pos=bin_search(arr,(2*arr[i]),n);
		//	printf("POS IS :%d\n",pos);
			if(pos!=-1) {
				if(boolean[pos]==0) {
					/*int flag=0;
					while(arr[pos]==(2*arr[i])&& boolean[pos]==0 && pos>=0) {
						pos--;
						flag=1;
					}
					if(arr[pos]==(2*arr[i]) && flag==1) {
						answer++;
						boolean[pos]=0;
						continue;
					}
					flag=0;
					while(arr[pos]==(2*arr[i])&& boolean[pos]==0 && pos<n) {
						flag=1;
						pos++;
					}
					if(arr[pos]==(2*arr[i]) && flag==1) {
						answer++;
						boolean[pos]=0;
						continue;
					}	*/
					continue;
				}
				else {
					answer++;
					boolean[pos]=0;
				}
			}
			else
				boolean[pos]=0;
		}
		printf("%llu\n",answer);
	}
}
