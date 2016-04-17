#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#define LOOP for(int i=0;i<n;i++)
#define TEST while(t--)

char ch[100001];
int i=0;

int max_depth() {
	if(ch[i]=='l') {
		return 0;
	}
	else {
		i++;
		int left=max_depth();
		i++;
		int right=max_depth();
		return (left>=right?left+1:right+1);
	}
}

int main(void) {
	int t;
	scanf("%d",&t);
	TEST {
		scanf("%s",ch);
		i=0;
		printf("%d\n",max_depth());
	}
}
