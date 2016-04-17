#include<stdio.h>
#include<stdlib.h>

int *Merge(int *arr1,int *arr2,int len1,int len2,int *sort) {
	int temp1,temp2,count;
	temp1=temp2=count=0;
	while(temp1<len1 && temp2<len2) {
		while(arr1[temp1]<arr2[temp2] && (temp1<len1 && temp2<len2)) {
			sort[count++]=arr1[temp1++];
		}
		while(arr1[temp1]>arr2[temp2] && (temp1<len1 && temp2<len2)) {
			sort[count++]=arr2[temp2++];
		}
	}
	while(temp1==len1 && (temp2<len2)) {
		sort[count++]=arr2[temp2++];
	}
	while((temp1)<=len1 && (temp2)==len2) {
		sort[count++]=arr1[temp1++];
	}
	
	return sort;
}

int main(void) {
	int *arr1,*arr2;
	printf("Enter the Number of Elements you would like your first array to have : ");
	int num1,num2,count;
	scanf("%d",&num1);
	printf("\nEnter the Number of Elements you would like your second array to have : ");
	scanf("%d",&num2);
	arr1=(int*)malloc(sizeof(int)*(num1));
	arr2=(int*)malloc(sizeof(int)*(num2));
	printf("\nEnter the Elements of Array One in Sorted Order : \n");
	int ele;
	count=0;
	while(count<num1) {
		scanf("%d",&ele);
		arr1[count++]=ele;
	}
	printf("\nEnter the Elements of Array Two in Sorted Order : \n");
	count=0;
	while(count<num2) {
		scanf("%d",&ele);
		arr2[count++]=ele;
	}
	//Sorted Merged array
	int *sort;
	sort=(int*)malloc(sizeof(int)*(num1+num2));
	sort=Merge(arr1,arr2,num1,num2,sort) ;
	count=0;
	while(count<(num1+num2)) {
		printf("%d  ",sort[count++]);
	}
}

