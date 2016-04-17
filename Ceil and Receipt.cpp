#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int k=n/2048;
		int count=k;
		n=n-(k*2048);
		if(n%2048!=0){
		while(1) {
			int p=log2(n);
			if(pow(2,p)==n) {
				count++;
				break;
			}
			else if (((pow(2,p))-1)==n) {
				count+=(p+1);
				break;
			}
			else {
				n-=int(pow(2,p));
				count++;
			}
		}
		printf("%d\n",count);
    }
    else {
    	printf("%d\n",count);
	}
    }
}
