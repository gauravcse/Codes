#include<stdio.h>
int output;
int hexconvert(int x);
int main() {
	int a;
	printf("THE NUMBER TO BE CONVERTED TO OCTAL ");
	scanf("%d",&a);
	printf("\n");
	int result=hexconvert(a);
	while(result>0){
    	printf("%d",result%10);
    	result/=10;
    }
}
int hexconvert(int x) {
	if(x<8) {
		output=(output*10)+x;
		return output;
	}
	else {
		output=output*10+(x%8);
		hexconvert(x/8);
	}
	  
}
