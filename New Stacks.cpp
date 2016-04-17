#include<stdio.h>
#include<stdlib.h>
#define LOOP for(int i=0;i<n;i++)
#define TEST while(t--)
#define T int t
#define TD scanf("%d",&t)
#define N int n
#define ND scanf("%d",&n)
#define LLU long long unsigned

int top;
int check(int arr[],int r) { 
	int pos=-1;
	int i=0;
	int max=arr[top];
	int left=0;
	int right=top;
	int mid=0;
	if(r>arr[top]){
		return pos;
	}
	else {
		//printf("Right is : %d\n",right);
		while(left<=right) {
			mid=(left+right)/2;
			if(arr[mid]<=r)
				left=mid+1;
			else if(arr[mid]>r)
				right=mid-1;

		}
		if(arr[mid]<=r) {
			while(arr[mid]<=r){
				mid++;
			}
		}
	//	printf("Mid is : %d\n",mid);
		return mid;
}
//	printf("Mid is :%d\n",mid);
	/*while(arr[i]!=0) {
		max=max<arr[i]?arr[i]:max;
		i++;
	}*/
	//*while(arr[i]<=r && i<=top){
		/*if(arr[i]>r) {
			if(arr[i]<=max) {
				max=arr[i];
				pos=i;
			}
		}*/
	/*	i++;
	}*/
	//printf("i value returned %d\n",i);
/*	if(mid==0)
		return pos;
	else
		return mid;*/
		
}
int main(void) {
	T;
	TD;
	TEST {
		N;
		ND;
		int arr[n+1];
		int final[n+1];
		for(int i=0;i<n;i++)
			final[i]=0;
		top=-1;
		for(int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
		}

		for(int i=0;i<n;i++) {
		/*	for(int k=0;k<top+1;k++) {
				printf("%d ",final[k]);
			}
			printf("\n");*/

			int con=arr[i];
			int pos=check(final,con);
		//	printf("POS IS : %d\n",pos);
			if(pos==-1) {
				final[++top]=con;
				/*for(int k=0;k<top+1;k++) {
					printf("%d ",final[k]);
				}
				printf("\n");*/
			}
			else {
				final[pos]=con;
				/*for(int k=0;k<top+1;k++) {
					printf("%d ",final[k]);
				}
				printf("\n");*/
			}
		}
		printf("%d ",top+1);
		for(int i=0;i<top+1;i++) {
			printf("%d ",final[i]);
		}
		printf("\n");
	}
	
}
