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

int main(void) {
	T;
	TD;
	int count=1;
	TEST {
		char *arr;
		scanf("%s",arr);
		int maxLen=0;
		for(int p=0;p<=(strlen(arr)-3);p++) {
			int len=0;
			if(arr[p]=='1' && arr[p+1]=='0' && arr[p+2]=='0') {
				len=3;
				arr[p]=arr[p+1]=arr[p+2]='2';
				if(p==0) {
					p+=2;
					if(len>maxLen)
						len=maxLen;
					continue;
				}
				else {
					p--;
					while(arr[p]=='1' && arr[p+len+1]=='0' && arr[p+len+2]=='0') {
						len+=3;
						arr[p]=arr[p+len+1]=arr[p+len+2]='2';
						p--;
						if(p<0) {
							p+=len;
							if(len>maxLen)
								len=maxLen;
							break;;
						}
					}
					if(len>maxLen)
						len=maxLen;
				}
			}
	
		}
		printf("Case %d:%d",count++,maxLen);
	}
	
}
