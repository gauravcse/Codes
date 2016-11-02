/***	OFFSETOF MACRO	***/

#include<stdio.h>
#include<stddef.h>
#define OFFSETOF(type,var) ((size_t)&(((type*)0)->var))

typedef struct str {
	long long unsigned d;
	char c;
	int i;
}str;

int main(void) {
	printf("%d", OFFSETOF(str, c) );
}
