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

int top;
int check(int arr[],int r) { 
	int pos=-1;
	int i=0;
	int max=0;
	while(arr[i]!=0) {
		max=max<arr[i]?arr[i]:max;
		i++;
	}
	i=0;
	while(arr[i]!=0 ){
		if(arr[i]>r) {
			if(arr[i]<=max) {
				max=arr[i];
				pos=i;
			}
		}
		i++;
	}
	return pos;
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
			/*for(int k=0;k<top+1;k++) {
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
