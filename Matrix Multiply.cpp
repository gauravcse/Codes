#include<stdio.h>
#include<stdlib.h>
void multiply(int a[10][10],int b[10][10],int c[10][10],int x,int w,int z);
void fillarray(int a[10][10],int x,int y);
void printarray(int a[10][10],int x,int y);
int main() {
	printf("ENTER THE DIMENSIONS OF THE FIRST MATRIX : ");
	int m1,n1;
	scanf("%d %d",&m1,&n1);
	printf("\n");
	int m2,n2;
	printf("ENTER THE DIMENSIONS OF THE SECOND MATRIX : ");
	scanf("%d %d",&m2,&n2);
	printf("\n");
	if(n1==m2) {
		int arr1[10][10];
		int arr2[10][10];
		fillarray(arr1,m1,n1);
		fillarray(arr2,m2,n2);
		int arr3[10][10];
		multiply(arr1,arr2,arr3,m1,m2,n2);
		printarray(arr3,m1,n2);
	}
	else {
		printf("ARRAY CANNOT BE MULTIPLIED");
		exit(0);
	}
	
}
void fillarray(int a[10][10],int x,int y) {
	for(int i=0;i<x;i++) {
		for(int j=0;j<y;j++){
			printf("ENTER THE ELEMENT AT THE %d th ROW AND %d th COLUMN",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
}
void printarray(int a[10][10],int x,int y) {
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			printf("%d  ",a[i][j]);
		}
		printf("|\n|");
	}
}
void multiply(int a[10][10],int b[10][10],int c[10][10],int x,int w,int z) {
	for(int i=0;i<x;i++) {
		for(int j=0;j<z;j++) {
			int element=0;
			for(int k=0;k<w;k++) {
				element+=a[i][k]*b[k][j];
			}
			c[i][j]=element;
	    }
	}
}
