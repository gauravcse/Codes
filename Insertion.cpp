#include<stdio.h>
#include<stdlib.h>
int main(void) {
	int len;
	scanf("%d",&len);
	printf("\n");
	int* arr=(int*)malloc(len*sizeof(int));
	for(int i=0;i<len;i++) {
		scanf("%d ",(arr+i));
	}
	for(int i=0;i<len;i++) {
		printf("%d \n",arr[i]);
	}
	
	
	
	
}

