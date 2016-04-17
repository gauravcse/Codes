#include<stdio.h>
#include<string.h>

void lin_search();
void bin_search();

main(){

	int i,choice;
	char array[10][10],word[10];
	FILE *fp;
	
	fp=fopen("goru3.txt","r");
	
	for(i=0;i<10;i++)
		fscanf(fp,"%s",array[i]);
		
	printf("Enter the word to search: ");
	scanf("%s",word);
	printf("\t1. Linear Search\n\t2. Binary search\n");
	printf("Your Choice: ");
	scanf("%d",&choice);
	
	if(choice==1)
		lin_search(array,word);
	else if(choice==2)
		bin_search(array,word);
	else
		printf("Invalid Input\n");
		
	return 0;
}

void lin_search(char arr[][10], char *word){

	int i;
	
	for(i=0;i<10;i++){
		if(!strcmp(arr[i],word)){
			printf("Word found at index %d\n",i);
			break;
		}
	}
	
	if(i==10)
		printf("Not Found!!\n");
		
}

void bin_search(char arr[][10], char *word){

	int high=9,low=0,mid,flag=0;
	
	while(high>=low){
		mid=(high+low)/2;
		if(strcmp(arr[mid],word)==0){
			printf("Word found at index %d\n",mid);
			flag=1;
			break;
		}
		else if(strcmp(arr[mid],word)>0)
			high=mid-1;
		else
			low=mid+1;
	}
	
	if(flag==0)
		printf("Not Found!!\n");
		
}
