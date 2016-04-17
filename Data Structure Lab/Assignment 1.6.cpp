#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char name[30];  //Global variable to store the name
char number_equivalent[] = {'0','1','2','3','4','5','6','7','8','9'};
int digits_in_num(int n);
long long unsigned prime_generator() ;
	    

int main(void) {
	printf("Please enter your name : ");
	scanf("%[^\n]s",name);
	printf("\n");
	int len=strlen(name);  // The length of the name
	char name_to_number[3*len];    //To save the name as a string of number code
	int count=0;    // As a counter
	for(int i=0;i<len;i++) {
		int num=(int)name[i];
		int digits=digits_in_num(num);
		    while(digits!=0 && num!=32) {
		    	int dig=(num)/(pow(10,(digits-1)));
		    	digits--;
		    	name_to_number[count++]=number_equivalent[dig];
		    	num=num-(dig*pow(10,digits));
			}
	}
	name_to_number[count]='\0';
	printf("\nThe name in number code is :%s \n",name_to_number);
	int string_len=strlen(name_to_number);   // Length of the string of characters
	int number_array[string_len];
	for(count=0;count<string_len;count++) {
		number_array[count]=(int)(name_to_number[count])-48;
	}
	
	// Now we will compute whether the length of the array is even or odd
	
	int flag= string_len % 2;
	int first,second;              //Contains to halves of the array
	
	switch(flag) {
		
		case 1 : first= (string_len/2)+1;
		         second=string_len/2;
		         break;
		case 0 : first= (string_len/2);
		         second=string_len/2;
		         break;
	}
//	printf("\n%d   %d ",first,second);
	long long unsigned part_one=0,part_two=0;
	
	// To find the first part of the array
	
	for(count=0;count<first;count++) {
		part_one=(part_one*10)+number_array[count];
	}
	
	// To find the second part of the array	
	
	for(count=first;count<(first+second);count++) {
		part_two=(part_two*10)+number_array[count];
	}
	
	printf("The first half of the number is : %llu \n \t\t\nThe second half of the number is :  %llu\n",part_one,part_two);
	long long unsigned add = part_one + part_two;
	printf("\nAfter addition of the two parts we get : %llu \n",add);
	
	// Now the user will generate a prime number which is long
	
	long long unsigned prime=0;
	prime= prime_generator();

	long long unsigned modulus = add % prime;
	printf("The final answer is : %llu",modulus);
}

int digits_in_num(int n) {
	int dig=0;
	while(n>0) {
	    n/=10;
		dig++;	
	}
	return dig;
}

long long unsigned prime_generator() {
	
	/*
	 * The potetial primes that can be used as an input are :
	 *179426549    32416187827    22801764187    
	 *etc as input
	*/

	printf("Enter a large number which is prime\n");
    long long unsigned prime;
	scanf("%llu",&prime)	;
	return prime;

}

