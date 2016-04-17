#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(void) {
	char *t;
	t=(char*)malloc(sizeof(char)*5);
	scanf("%s",t);
	while(strcmp(t,"00e0")) {
		int first=(int)t[0]-48;
		int second=(int)t[1]-48;
		int last=(int)t[3]-48;
		long num=(int)pow(10,last);
		long long unsigned result=((first*10)+second)*num;
		long long unsigned base=floor((log(result)/log(2)));
		long long unsigned expo=pow(2,base);
		base=result-expo;
		printf("%llu\n",(2*base+1));
		scanf("%s",t);
	}
}
