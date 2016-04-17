#include <stdio.h>
#include <limits.h>
#include <math.h>
int main(){
		time_t t;
		int seed=time(&t);
		srand(seed);
		int prime,n,i;
		long int no,x;
		scanf("%d",&prime);//scan prime number
		scanf("%d",&n);//no of numbers
		printf("\n Numbers \t \t Remainder\n");
		
		for(i=0;i<n;i++){
			no=(rand()%1000000000000)+100000000;
			x=no%prime;
			printf("%ld \t %ld\n",no,x);
		}
		return 0;

}
