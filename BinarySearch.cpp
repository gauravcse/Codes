#include<stdio.h>
#include<stdlib.h>
int binarySearch(int a[],int s,int l,int u);
int main() {
	int len,count;
	scanf("%d",len);
	printf("\n");
	int *arr=(int*)malloc(len*sizeof(int));
	for(count=0;count<len;count++)
	arr[count]=count+1;
	int search;
	scanf("%d",&search);
	int pos=binarySearch(arr,search,0,len);
	if(pos!=-1)
	printf("\nTHE POSITION IN WHICH THE ELEMENT IS PRESENT IS %d",pos+1);
	else
	printf("ITEM NOT FOUND");
}
int binarySearch(int a[],int s,int l,int u) {
    if(l>u) {
    	return -1;
    }
    else
    {
    	int mid=(l+u)/2;
    	if(s>a[mid])
    	binarySearch(a,s,mid+1,u) ;
    	else if (s<a[mid])
    	binarySearch(a,s,l,mid-1) ;	
    	else if(s==a[mid])
    	return mid;
	}
}
