#include<iostream>
#define max 55

int dp[max]={1};
int arr[max];
int sign[max]={0};

int main(void) {
	int count;
	scanf("%d",&count);
	for(int i=0;i<count;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<count;i++) {
		for(int j=i-1;j>=0;j--) {
			if((sign[j]==0) || (sign[j]<0 && (arr[i]-arr[j])>0) || (sign[j]>0 && (arr[i]-arr[j]<0))) {
				dp[i]=dp[j]+1;
				sign[i]=arr[i]-arr[j];
				break;
			}	
		}
	}
	std::cout<<dp[count-1]<<std::endl;
}
