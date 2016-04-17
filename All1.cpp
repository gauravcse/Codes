#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int BinarySearch(int element,int upper,int* a,int lower);
void InsertionSort(int* arr,int len);
void fillarr(int*,int len);
void printarr(int* x,int len);
int main(void) {
	int* arr;
	int len;
	scanf("%d",&len);
	arr=(int*)(malloc(len*sizeof(int)));
	fillarr(arr,len);
	printarr(arr,len);
	InsertionSort(arr,len);
	printarr(arr,len);
	srand(time(NULL));
	int element;
	element=rand()%25;
	printf("\nELEMENT TO BE SEARCHED IS %d",element);;
	int position=BinarySearch(element,len,arr,0);
	if(position==-1)
	printf("\nSEARCH UNSUCCESSFUL");
	else
	printf("\nELEMENT FOUND AT POSITION %d",position);
	
}
void fillarr(int* x,int len) {
	srand((int)time(NULL));
	for(int i=0;i<len;i++) {
		x[i]=rand()%25;
	}
	
}
void printarr(int* x,int len) {
	printf( "\n");
	for(int i=0;i<len;i++)
	  printf("%d  ",x[i]);
}
int BinarySearch(int element,int upper,int* a,int lower){
	if(lower>upper)
	  return -1;
	int mid=(upper+lower)/2;
	if(a[mid]==element)
	   return mid;
	else if(a[mid]>element)
	  return (BinarySearch(element,upper,a,mid+1));
	else if(a[mid]<element)
	  return (BinarySearch(element,mid-1,a,lower));
}
void InsertionSort(int* arr,int len) {
	for(int i=1;i<len;i++) {
		int j=i-1;
		int pos=arr[i];
		while((pos<arr[j])&&(j>=0)){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=pos;
	}
}
