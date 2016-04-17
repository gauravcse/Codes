#include<stdio.h>
#include<string.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int arr[n];
		memset(arr,0,n);
		int tom=0,ans=0;
		for(int j=0;j<n;j++) {
			scanf("%d",&arr[j]);
			int i=j+1;
			if((arr[j]%2==0 && i%2==0) || (i%2!=0 && arr[j]%2==0))
				ans=2;
			else
				ans=1;
			if((tom==0 && ans==1) || (tom==1 && ans==2))
				tom=1;
			else
				tom=0;
		}
		if(tom==1) 
			printf("%s\n","Tom Wins");
		else
			printf("%s\n","Hanks Wins");	
	}
}
