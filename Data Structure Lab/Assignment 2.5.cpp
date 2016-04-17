#include<stdio.h>
#include<stdlib.h>

int orderOfSort(int *arr,int len) {
	int flag=0;
	for(int i=0;i<len-1;i++) {
		if(arr[i]==arr[i+1])
			continue;
		else
			flag=1;
	}
	if(flag==1) {
		for(int i=0;i<len-1;i++) {
			if(arr[i]<=arr[i+1])
				continue;
			else
				flag=2;
		}
		if(flag==2) {
			for(int i=0;i<len-1;i++) {
			if(arr[i]>=arr[i+1])
				continue;
			else
				flag=3;
			}
		}
	
	}
	return flag;
}

int main(void) {
	int *arr;
	printf("Enter the Number of Elements you would like your array to have : ");
	int num,finalnum;
	scanf("%d",&num);
	finalnum=num;
	arr=(int*)malloc(sizeof(int)*(num+1));
	int count=0;
	printf("\nEnter the Elements\n");
	int ele;
	while(count<num) {
		scanf("%d",&ele);
		arr[count++]=ele;
	}
	
	int order=orderOfSort(arr,finalnum);
	if(order==1) {
		printf("ASCENDING ORDER");
	}
	else if(order==2) {
		printf("DESCENDING ORDER");
	}
	else if(order==0){
		printf("EQUAL");
	}
	else {
		printf("UNSORTED");
	}
	
}
