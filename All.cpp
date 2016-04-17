#include<stdio.h>
void swap(int* x,int* y);
int main() {
	int x,y;
	scanf("%d %d",&x,&y);
	  printf("Before swap a is %d\n", x);
        printf("Before swap b is %d\n", y);
	swap(&x,&y);
	printf("After swap a is %d\n", x);
        printf("After swap b is %d", y);
        return 0;
}
void swap(int* a ,int* b) {
	*a=*a-*b;
	*b=*b+*a;
	*a=*b-*a;
}
