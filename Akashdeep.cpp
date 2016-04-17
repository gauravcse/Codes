#include<stdio.h>
#include<stdlib.h>

int cmpfnc(const void* a,const  void* b) {
	return (*(int*)b-*(int*)a);
}

int main(void) {
	int n;
	printf("Enter the value of N : ");
	scanf("%d",&n);
	int numbers[n+1];
	int operators[n];
	printf("Enter the Numbers and Enter the operators and terminate it by any character : \n");
	for(int i=0;i<n;i++)
		scanf("%d ",&numbers[i]);
	
	for(int i=0;i<n-1;i++) {
		char ch;
		scanf("%c ",&ch);
		if(ch=='*') 
			operators[i]=4;
		else if(ch=='+')
			operators[i]=3;
		else if(ch=='-')
			operators[i]=2;
		else if(ch=='/')
			operators[i]=1;
	}
	
	/*for(int i=0;i<n-1;i++)
		printf("%d	",operators[i]);
	printf("\n\n");*/
	
	qsort(numbers,n,sizeof(int),cmpfnc);
	qsort(operators,n,sizeof(int),cmpfnc);
	int top=0;
	/*for(int i=0;i<n;i++)
		printf("%d	",numbers[i]);
	printf("\n\n");
	for(int i=0;i<n;i++)
		printf("%d	",operators[i]);
	printf("\n\n");*/
	int ans=0;
	// This is a stack implemented internally instead of externally declaring push pop or top opeartions
	while(top<n) {
		int op=operators[top+1];	// POP 
		if(op==4) 
			ans=numbers[top]*numbers[top+1];
		else if(op==3) 
			ans=numbers[top]+numbers[top+1];
		else if(op==2) 
			ans=numbers[top]-numbers[top+1];	
		else if(op==1) 
			ans=numbers[top]/numbers[top+1];
		top++;
		numbers[top]=ans;		// Pseudo PUSH Operation
		for(int i=0;i<n;i++)
			printf("%d	",numbers[i]);
		printf("\n\n");
	}
	printf("The maximum values : %d",ans);
	
}

