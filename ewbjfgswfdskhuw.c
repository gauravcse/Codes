#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
int main(int argc,char *argv[]) {
	int a,b;
	if(argc!=4) {
		printf("WRONG OUTPUT");
		exit(0);
	}
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	printf("%d %d %s",a,b,argv[3]);
	return 0;
	
}
	
	
