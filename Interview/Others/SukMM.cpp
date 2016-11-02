#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define mod 1000000007
int cmpfn (const void * a, const void * b)
{
   return ( *(long long int*)a - *(long long int*)b );
}
 
long long int modulo(int a, int b) {
    long long int r = a % b;
    return r < 0 ? r + b : r;
}
int main(){
 
int t;
scanf("%d",&t);
while(t--){
	int n,k;
	scanf("%d %d",&n,&k);
	int i,j,count=0;
	 
	long long int arr[n],element;
	for(i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	qsort(arr,n,sizeof(long long int),cmpfn);
	 
	long long int product1=1,product2=1,product=1;
	if(k%2==0){
		for(i=0,j=n-1;i<n,j>=0;){
			if(count==k)
				break;
			 
			if(arr[i]*arr[i+1]<=arr[j]*arr[j-1]){
				product1=arr[j];
				product2=arr[j-1];
				product=((product%mod) * (product2 * product1)%mod)%mod;
				j-=2;
				count+=2; 
			}
			else {
				product1=arr[i];
				product2=arr[i+1];
				product=((product%mod) * (product2 * product1)%mod)%mod;
				i+=2;
				count+=2;
			}
		}
		printf("%lld\n",product);
	}
	else {
	for(i=0,j=n-1;i<n,j>=0;){
		if(count==k-1){
			element=arr[j];
			break;
		}
	 
		if(arr[i]*arr[i+1]<=arr[j]*arr[j-1]){
			product1=arr[j];
			product2=arr[j-1];
			product=((product%mod) * (product2 * product1)%mod)%mod;
			j-=2;
			count+=2; 
		}
		else {
			product1=arr[i];
			product2=arr[i+1];
			product=((product%mod) * (product2 * product1)%mod)%mod;
			i+=2;
			count+=2;
		}
	}
	 
	printf("%lld\n",modulo((modulo(product,mod) * modulo(element,mod)),mod)); 
	 
	}
 
}
 
 
 
return 0;
} 
