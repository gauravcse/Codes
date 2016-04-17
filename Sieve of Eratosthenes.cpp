#include<stdio.h>
#include<stdlib.h>
int main(void) {
    printf("ENTER THE NUMBER UPTO WHICH PRIME IS TO BE FOUND OUT");
    int num;
    scanf("%d",&num);
    int *arr;
    arr=(int*)malloc((num+1)*sizeof(int));
    for(int i=1;i<=num;i++) {
    	arr[i]=0;
	}
	for(int i=2;i<=(num)/2;i++) {
		for(int j=2;(j*i)<=num;j++) {
			arr[(i*j)]=1;
		}
		if(i%2!=0)
		  i++;
	}
	for(int i=2;i<=num;i++) {
		if(arr[i]==0)
		printf("%d",i);
	}
	  
}
