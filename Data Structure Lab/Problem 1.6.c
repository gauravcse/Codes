#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *str_to_int(char *str1, char *str2){

	int l1,l2,i,*num_arr,l;
	
	l1=strlen(str1);
	l2=strlen(str2);
	
	num_arr=malloc((2*l1 + 2*l2 + 1)*sizeof(*num_arr));
	
	l=0; i=0;
	while(str1[i]!='\0'){
		num_arr[2*l]=((int)str1[i])/10;
		num_arr[2*l + 1]=((int)str1[i])%10;
		l++; i++;
	}
	
	i=0;
	while(str2[i]!='\0'){
		num_arr[2*l]=((int)str2[i])/10;
		num_arr[2*l + 1]=((int)str2[i])%10;
		l++; i++;
	}
	
	num_arr[2*l1 + 2*l2]=-1;
	
	return num_arr;
	
}

int division(int *num, int prime, int part){

	while(part<=prime && *num>=0){
		part=10*part+*num;
		num++;
	}
	
	while(part-prime>=0){
		part=part-prime;
	}
	
	if(*num<0)
		return part;
		
	return division(num,prime,part);
		
}

int *addition(int *num){

	int *ans,n1=0,n2,i,carry=0;
	
	while(num[n1]>=0)
		n1++;
		
	n2=n1/2;
	ans=malloc((n2+2)*sizeof(*ans));
	ans[n2+1]=-1;
	
	i=n1;
	while(--i>(n1/2)){
		ans[n2]=(num[i]+num[i-(n1/2)]+carry)%10;
		carry=(num[i]+num[i-(n1/2)]+carry)/10;
		n2--;
	}
	
	ans[n2]=carry;
	
	return ans;
	
}

int main(){

	char name[50],surname[50];
	int prime=100,*int_string,i,*add,ans;
	
	printf("Enter your FULL name: ");
	scanf("%s%s",name,surname);
	
	int_string=str_to_int(name,surname);
	
	printf("Converted Integer: ");
	i=0;
	while(int_string[i]>=0)
		printf("%d",int_string[i++]);
	printf("\n");
	
	add=addition(int_string);
	
	ans=division(add,prime,0);
	printf("Here is the final answer: %d\n",ans);
	
}
