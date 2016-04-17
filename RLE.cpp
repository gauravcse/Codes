#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#define LOOP for(int i=0;i<n;i++)
#define TEST while(t--)

int main(void) {
	char ch[100001];
	char alpha[100000];
	int length[100000];
	while(scanf("%s",&ch)!=EOF) {
		int count=0;
		int l=strlen(ch);
		for(int i=0;i<l;i++) {
			char current=ch[i];
			int len=1;
			while(ch[i+1]==current) {
				i++;
				len++;
			}
			alpha[count]=current;
			length[count]=len;
			count++;
		}
		for(int i=0;i<count;i++) {
			if(length[i]>3) {
				printf("%d!%c",length[i],alpha[i]);
			}
			else {
				if(length[i]==1) {
					printf("%c",alpha[i]);
				}
				else if (length[i]==2){
					printf("%c%c",alpha[i],alpha[i]);
				}
				else {
					printf("%c%c%c",alpha[i],alpha[i],alpha[i]);
				}
			}
		}
		printf("\n");
	}
	
}
