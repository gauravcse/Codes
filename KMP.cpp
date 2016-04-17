#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *LPSCompute(char *pat,int M);

void KMP(char *text,char *pat) {
	int M=strlen(pat);
	int N=strlen(text);
	//printf("%d      %d",M,N);
	int *lps;
	lps=LPSCompute(pat,M);
	int i=0,j=0;
//	printf("Pattern : %s",pat);
//	printf("Text : %s\n",text);
	while(i<N) {
		while(pat[j]==text[i]) {
			//printf("%c\n",pat[j]);
			i++;
			j++;
		};
//		printf("%d  %d  %d\n",i,j,N);
		if(j==M) {
			printf("Pattern Found at position : %d\n",i-M);
			j=lps[j-1];
		}
		else if(i<N && pat[j]!=text[i]) {
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
	free(lps);
}

int *LPSCompute(char *pat,int M) {
	int *lps;
	lps=(int*)(malloc(sizeof(int)*M));
	memset(lps,0,M);
	int len=0;
	lps[0]=0; // First index of LPS Array is always 0
	int i=1;
	while(i<M) {
		if(pat[i]==pat[len]) {
			len++;
			lps[i]=len;
			i++;
		}
		else {
			if(len!=0) {
				len=lps[len-1];
			}
			else {
				lps[i]=0;
				i++;
			}
		}
	}
	return lps;
}

int main(void) {
	char *pattern,*text;
	text=(char*)malloc(sizeof(char)*1000);
	pattern=(char*)malloc(sizeof(char)*100);
	scanf("%s",text);
	scanf("%s",pattern);
	KMP(text,pattern);
}
