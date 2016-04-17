#include<stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		char arr[20];
		int count=0;
		char ch;
		while(ch=getchar()!='\n')
		    arr[count++]=ch-'0';
		int i;
		for(i=0;i<count;i++)
		printf(" %c",arr[i]);
	}
 }
