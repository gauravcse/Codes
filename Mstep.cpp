#include<stdio.h>
#include<math.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int arr[n*n+1][2];
		for(int i=1;i<=(n*n);i++) {
			int num;
			scanf("%d",&num);
			if(i%n!=0) {
				arr[num][0]=i/n;	
				arr[num][1]=i%n;
			//	printf("%d %d \n",arr[num][0],arr[num][])
			}
			else {
				arr[num][0]=i/n-1;
				arr[num][1]=n;
			}
		}
		int sum=0;
		for(int i=1;i<(n*n);i++) {
			int x=fabs((arr[i][0]-arr[i+1][0]));
			int y=fabs((arr[i][1]-arr[i+1][1]));
			sum+=x+y;
		}
		printf("%d\n",sum);
	}
}
