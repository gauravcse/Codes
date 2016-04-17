#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void) {
	char *c,*s;
	int x=0,y=0;
	char ch;
	while(ch=getchar()!='\n') {
		c[x++]=ch;
	}
	printf("\n");
	c[x]='\0';
	printf("%s",c);
	for(;y<x;y++)
	printf("%c",c[y]);
	
}
