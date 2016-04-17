#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b);
int main() {
	int a,b,c,d;
	scanf("%d %d",&a,&b);
	scanf("%d %d",&c,&d);
	int den=b*d;
//	printf("%d\n",den);
	int num=((a*d)+(b*c));
//	printf("%d\n",num);
	int div;
	if(num>den)
    div=gcd(num,den);
	else if(num<den)
    div=gcd(den,num);
    else {
    printf("1");
    exit(0);
    }
 //   printf("%d\n",div);
	den/=div;
	num/=div;
	printf("%d / %d",num,den);
}
int gcd(int a,int b) {
	if(b==0)
	  return a;
	else 
	  gcd(b,a%b);
}

