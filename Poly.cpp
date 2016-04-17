#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

float* fillpoly(int arr[]) {
	char ch[10000];
	char temp;
	scanf("%c",&temp);
	int count=0;
	while(temp!='\n') {
		ch[count++]=temp;
		scanf("%c",&temp);
	}
	int len=count;
	count=0;
	while(count<len) {
		int coeff=0;
		int pow=0;
		while(ch[count]!='x') {
			int num=ch[count]-48;
			coeff=coeff*10+num;
			count++;
		}
		count++;
		while(ch[count]>=48 && ch[count]<58) {
			int num=ch[count]-48;
			pow=pow*10+num;
			count++;
		}
		arr[pow]=coeff;
		count++;
	}
	return arr;
}
int main(void) {
	float poly[MAX];
	float poly1[MAX];
	poly=fillpoly(poly);
	poly1=fillpoly(poly1);
	
}
