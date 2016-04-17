#include<stdio.h>
int fact_in_rec(int);
int fact_in_ite(int);
main(){
	int choice,n;
	printf("Enter the number: ");
	scanf("%d",&n);
	printf("\t1. Recursive\n\t2. Iterative\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Factorial of %d is %d\n",n,fact_in_rec(n));
			break;
		case 2:
			printf("Factorial of %d is %d\n",n,fact_in_ite(n));
			break;
		default:
			printf("Invalid choice !!\n");
			break;
	}
	return 0;
}
int fact_in_rec(int n){
	if(n==1)
		return 1;
	else
		return n*fact_in_rec(n-1);
}
int fact_in_ite(int n){
	int pro=1,i=1;
	while(i<=n){
		pro=pro*i;
		i++;
	}
	return pro;
}
