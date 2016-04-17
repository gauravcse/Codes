#include<stdio.h>
#include<math.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,m;
		scanf("%d %d",&n,&m);
		int arr[m];
		int one_count=0;
		for(int i=0;i<m;i++) {
			scanf("%d",&arr[i]);
			if(arr[i]==1)
				one_count++;
		}
		int sum=0;
		int rest=m-one_count;
		if(one_count==m) {
			sum=(m%2==0)?m/2:(m-1)/2;
				printf("Block 0\n");
		}
		else if(one_count==0) 
			sum=m-1;
		else if((2*one_count-1)<rest) {
			sum=one_count;
			rest=rest-(2*one_count-1)+1;
			sum+=rest-1;
			if(one_count==1)
				sum--;
		}
		else if((2*one_count-1)==rest) {
			sum=one_count+1;
			printf("Block 2\n");
		}
		else {
			int number_of_ones=one_count-rest+1;
			sum=number_of_ones;
			int num_of_blocks=number_of_ones+1;
			sum+=num_of_blocks%2==0?num_of_blocks/2:(num_of_blocks-1)/2;
			printf("Block 3\n");
		}
		printf("%d\n",sum);
	}
}
