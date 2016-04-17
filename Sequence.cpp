#include<stdio.h>
int main(void) {
	int cases1,cases2;
//	printf("ENTER THE CASES IN ARRAY 1");
	scanf("%d",&cases1);
	int arr1[cases1+1];
	for(int i=0;i<cases1;i++)  {
       scanf("%d",&arr1[i]);
	}
//	printf("ENTER THE CASES IN ARRAY 2");
	scanf("%d",&cases2);
	int arr2[cases2+1];
	for(int i=0;i<cases2;i++)  {
       scanf("%d",&arr2[i]);
	}
	int min=cases1<=cases2?cases1:cases2;
	for(int i=0;i<=min;i++) {
		if(arr1[i]==arr2[i])
		  printf("%d" ,i+1);
		  
	}
	return 0;
	
	}
