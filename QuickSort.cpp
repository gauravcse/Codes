#include<stdio.h>
#include<stdlib.h>
int *arr;
int len;
void swap(int arr[],int i,int j) {
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int partition(int arr[],int l,int r) {
	int j=l;
	int P=arr[l];
//	printf("Pivot is %d \n",P);
	for(int i=l;i<r;i++) {
		if(arr[i+1]>P) {
		//	printf("Swapping %d with %d \n",arr[i+1],arr[j+1]);
			swap(arr,i+1,j+1);
			continue;
		}
		else {
		//	printf("Swapping %d with %d \n",arr[i+1],arr[j+1]);
			swap(arr,i+1,j+1);
			j++;
			continue;
		}
	}
	swap(arr,l,j);
	return j;
}

void quicksort(int arr[],int left,int right) {
	if(left>=right)
		return;
	else {
		int border=partition(arr,left,right);
		quicksort(arr,left,border);
		quicksort(arr,border+1,right);
	}
	/*for(int i=0;i<len;i++) {
		printf("%d    ",arr[i]);
	}*/
	
}

int main(void) {
	scanf("%d",&len);
	arr=(int*)malloc(sizeof(int)*len);
	for(int i=0;i<len;i++) {
		scanf("%d",(arr+i));
	}
//	printf("\n");
	quicksort(arr,0,len-1);
//	printf("%d\n",partition(arr,0,len-1));
	printf("\nArray Print : ");
	for(int i=0;i<len;i++) {
		printf("%d    ",arr[i]);
	}
	printf("\n");
}

