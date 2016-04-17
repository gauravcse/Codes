#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

/*int cmpfnc(const void* a,const void* b) {
	return (*(int*)a-*(int*)b);
}*/

int main(void) {
	int n,k;
	scanf("%d %d",&n,&k);
	int arr[n];
	long long sum=0;
	int negative=0;
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		sum+=abs(arr[i]);
		if(arr[i]<0)
			negative++;
	}
	if(k==n) {
		if(negative%2==0)
			printf("%lld",sum);
		else
			printf("%lld",-1*sum);	
		return 0;
	}
	sort(arr,arr+n);
	int left,right;
	left=0;
	right=n-1;
	negative=0;
	int flag=0;
	sum=0;
	while(k>=2) {
		/*int right_sum=arr[right]+arr[right-1];
		int left_sum=arr[left]+arr[left-1];
		if(abs(left_sum)>abs(right_sum)) {
			left+=2;
			k-=2;
			sum+=left_sum;
		}
		else {
			sum+=abs(arr[right]);
			right--;
			k--;
		}*/
		if(arr[left]<0 && arr[left+1]<0 && arr[right]>=0 && arr[right-1]>=0) {
			int right_sum=arr[right]+arr[right-1];
			int left_sum=arr[left]+arr[left+1];
			if(abs(left_sum)>abs(right_sum)) {
				left+=2;
				k-=2;
				sum+=abs(left_sum);
				negative+=2;
			}
			else {
				sum+=abs(arr[right]);
				right--;
				k--;
			}
			
		}
		else if(arr[left]<0 && arr[left+1]<0 && arr[right]<0 && arr[right-1]<0) {
			flag=1;	// Even number K means from left : Odd number k means from right
			break;
		}
		else if(arr[left]>=0 && arr[left+1]>= 0 && arr[right]>=0 && arr[right-1]>=0) {
			flag=2;	// Always from right
			break;
		}
		else if(arr[left]<0 && arr[left+1]>=0) {
			//printf("%lld is Sum Status\n K status : %d\n",sum,k);
			flag=2;
			break;
		}
	}
	if(flag==2) {
		//printf("REACHED\n");
		while(k>=1) {
			k--;
			if(arr[right]<0)
				negative++;
			sum+=abs(arr[right]);
			right--;
			//printf("%lld is Sum Status\n K status : %d\nNegative Status :%d\n",sum,k,negative);
		}
	}
	else if(flag==1) {
		if(k%2==0) {
			while(k>0) {
				sum+=(abs(arr[left]));
				left++;
				negative++;
				k--;
			}
		}
		else {
			while(k>0) {
				sum+=(abs(arr[right]));
				right--;
				negative++;
				k--;
				//printf("%lld is Sum Status\n K status : %d\n",sum,k);
			}
		}
	}
	if(k==1) {
		if(arr[left]<0 && arr[left+1]<0 && arr[right]<0 && arr[right-1]<0) {
			sum+=abs(arr[left]);
			negative++;
		}
		else {
			sum+=abs(arr[right]);
		}
		//printf("%lld is Sum Status\n K status : %d\n",sum,k);
	}
	if(negative%2==0) {
		printf("%lld",sum);
	}
	else {
		printf("%lld",-1*sum);
	}
	
}
