#include<stdio.h>
int fibo_in_rec(int);
int fibo_in_ite(int);
main(){
	int choice,n;
	printf("Enter the position: ");
	scanf("%d",&n);
	printf("\t1. Recursive\n\t2. Iterative\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("%d 'th Fibonacci number is %d\n",n,fibo_in_rec(n));
			break;
		case 2:
			printf("%d 'th Fibonacci number is %d\n",n,fibo_in_ite(n));
			break;
		default:
			printf("Invalid choice !!\n");
			break;
	}
	return 0;
}
int fibo_in_rec(int n){
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return fibo_in_rec(n-1)+fibo_in_rec(n-2);
}
int fibo_in_ite(int n){
	int a,b,c,i;
	a=0; b=1;
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	i=2;
	while(i<=n){
		c=a+b;
		a=b; b=c;
		i++;
	}
	return c;
}
