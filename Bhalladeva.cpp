#include<stdio.h>
#include<stdlib.h>
#define max 100005

int cmpfnc(const void* a,const void* b) {
	return (*(int*)a-*(int*)b);
}

int main(void) {
	int n;
	scanf("%d",&n);
	int arr[n+1];
	int sum=0;
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}

	qsort(arr,n,sizeof(int),cmpfnc);
/*	for(int i=0;i<n;i++) {
		printf("%d	",arr[i]);
	}*/
	int q;
	scanf("%d",&q);
	while(q--) {
		int k;
		scanf("%d",&k);

		if(k==0)
			printf("%d\n",sum);
		else {
			int front=0,rear=n-1,ans=0;;
			while(front<=rear) {
				//printf("FRONT : %d    REAR : %d\n",front,rear);
				ans+=arr[front];
				front++;
				rear-=k;
				//printf("FRONT : %d    REAR : %d\n",front,rear);
			}
			printf("%d\n",ans);
		}
	}
}

