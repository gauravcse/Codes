#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#define LOOP for(int i=0;i<n;i++)
#define TEST while(t--)
#define T int t
#define TD scanf("%d",&t)
#define N int n
#define ND scanf("%d",&n)
#define LLU long long unsigned


int *prefixCompute(char *s,int l) {
	int *lps;
	lps=(int*)malloc(sizeof(int)*l);
	int i=1,len=0;
	lps[0]=0;
	while(i<l) {
		if(s[i]==s[len]) {
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

int checkSubstring(char *text,char *pat,int *lps) {
	int M=strlen(text);
	int n=strlen(pat);
	int i=0;
	int j=0;
	while(i<M) {
		while(text[i]==pat[j] && i<M && j<n) {
			i++;
			j++;
		};
		if(j==n)
			return 1;
		else if(i<M && pat[j]!=text[i]) {
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
	return 0;
}

int main(void) {
	char *m;
	m=(char*)malloc(sizeof(char)*100005);
	scanf("%s",m);
	N;
	ND;
	while(n--) {
		char *s;
		s=(char*)malloc(sizeof(char)*2005);
		scanf("%s",s);
		int len=strlen(s);
		int *lps;
		lps=(int*)malloc(sizeof(int)*len);
		lps=prefixCompute(s,len);
		int res=checkSubstring(m,s,lps);
		if(res)
			printf("%c\n",'Y');
		else
			printf("%c\n",'N');	
	}
}
