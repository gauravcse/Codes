#include<stdio.h>

void lin_search(int*, int);
void bin_search(int*, int);

main(){

	int array[10],i,number,choice;
	FILE *fp;
	
	fp=fopen("goru.txt","r");
	
	for(i=0;i<10;i++)
		fscanf(fp,"%d",&array[i]);
		
	printf("Enter the number to search: ");
	scanf("%d",&number);
	printf("\t1. Linear Search\n\t2. Binary search\n");
	printf("Your Choice: ");
	scanf("%d",&choice);
	
	if(choice==1)
		lin_search(array,number);
	else if(choice==2)
		bin_search(array,number);
	else
		printf("Invalid Input\n");
		
	return 0;
}

void lin_search(int *arr, int num){

	int i;
	
	for(i=0;i<10;i++){
		if(arr[i]==num){
			printf("Number found at index %d\n",i);
			break;
		}
	}
	
	if(i==10)
		printf("Not Found!!\n");
		
}
void bin_search(int *arr, int num){

	int high=9,low=0,mid,flag=0;
	
	while(high>=low){
		mid=(high+low)/2;
		if(arr[mid]==num){
			printf("Number found at index %d\n",mid);
			flag=1;
			break;
		}
		else if(arr[mid]>num)
			high=mid-1;
		else
			low=mid+1;
	}
	
	if(flag==0)
		printf("Not Found!!\n");
		
}
