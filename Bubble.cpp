#include<stdio.h>
#include<stdlib.h>
int main(void) {
	int *arr;
	int length;
	scanf("%d",&length);
	printf("\n");
	arr=(int*)malloc(length*sizeof(int));
	for(int i=0;i<length;i++)
	  scanf("%d",(arr+i));
	for(int i=0;i<length;i++){
		for(int j=0;j<(length-i-1);j++) {
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(int i=0;i<length;i++)
	    printf("%d ",arr[i]);
	}

