#include<stdio.h>
#include<string.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int arr[n];
		int flag[n];
		for(int i=0;i<n;i++) {
			flag[i]=0;
			scanf("%d",&arr[i]);
		}
		int f=0;
		for(int i=0;i<n;i++) {
			
			int num=arr[i];
			if(num>=n) {
				f=1;
				printf("NO\n");
				break;
			}
			//printf("%d\n",num);
			if(flag[num]==0) {
				//printf("ME VISITED\n");
				flag[num]=1;
			}
			else if(flag[n-num-1]==0) {
				//printf("ME VISITED 2\n");
				flag[n-num-1]=1;
			}
			else if(flag[num]==1 && flag[n-num-1]==1) {
				//printf("ME VISITED 3\n");
				f=1;
				printf("NO\n");
				break;
			}
			/*for(int j=0;j<n;j++)
				printf("%d\t",flag[j]);
			printf("\n");*/
		}
		if(!f) {
			printf("YES\n");
		}
	}
}
