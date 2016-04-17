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

struct star {
	int x;
	int y;
}star[1000005];

int main(void) {
	T;
	TD;
	TEST{
		int n,m;
		scanf("%d %d",&n,&m);
		int count=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				char ch;
				scanf("%c",&ch);
				if(ch=='*') {
					star[count].x=i+1;
					star[count].y=j+1;
					count++;
				}
			}
		
		}
		
		
	}
	
}
