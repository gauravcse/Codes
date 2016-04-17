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

LLU hash_fn(char *s);

typedef struct node {
	char *str;
	int flag;
}node;

int main(void) {
	T;
	TD;
	TEST {
		node* hash[101];
		for(int i=0;i<101;i++) {
			hash[i]=(node*)malloc(sizeof(node));
			hash[i]->str=(char*)malloc(sizeof(char)*16);
			hash[i]->flag=0;
		}
		int operations;
		scanf("%d",&operations);
		int total=0;
		while(operations--) {
			char *s;
			s=(char*)(malloc(sizeof(char)*20));
			scanf("%s",s);
			char string[16];
			int i=4,count=0;
			while(s[i]!='\0') {
				string[count++]=s[i++];
			}
			string[count]='\0';
			if(s[0]=='A') {
				long long unsigned key=hash_fn(s);
				int i=1;
				while(i<=20) {
					LLU pos=(key+(i*i)+(23*i))%101;
					if(!hash[pos]->flag){
						hash[pos]->flag=1;
						strcpy(hash[pos]->str,string);
						total++;
						break;
					}
					else if(strcmp(string,hash[i]->str)==0)
						break;
					i++;
				}
			}
			else if(s[0]=='D') {
			/*	char string[16];
				int i=4,count=0;
				while(s[i]!='\0') {
					string[count++]=s[i++];
				}*/
				//string[count]='\0';
				for(int i=0;i<=100;i++) {
					if(hash[i]->flag && strcmp(string,hash[i]->str)==0) {
						total--;
						hash[i]->flag=0;
					}
				}
			}
		}
		printf("%d\n",total);
		for(int i=0;i<101;i++) {
			if(hash[i]->flag) {
				printf("%d:%s\n",i,hash[i]->str);
			}
		}
		
	}
}

LLU hash_fn(char *s) {
	char string[16];
	int i=4,count=0;
	while(s[i]!='\0') {
		string[count++]=s[i++];
	}
	string[count]='\0';
	i=0;
	LLU key=0;
	while(i<count) {
		char ch=string[i];
		key=key+(LLU)ch*(i+1);
		i++;
	}
	key=(key*19)%101;
	return key;
}
