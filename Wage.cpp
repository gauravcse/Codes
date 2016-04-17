#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#define LOOP for(int i=0;i<r;i++)
#define LOOP1 for(int j=0;i<c;i++)
#define TEST while(t--)
#define T int t
#define TD scanf("%d",&t)
#define N int n
#define ND scanf("%d",&n)
#define LLU long long unsigned

int main(void) {
	T;
	TD;
	TEST {
		int r,c,n;
		scanf("%d %d %d",&r,&c,&n);
		char game[r][c];
		LOOP {
			LOOP1 {
				scanf("%d",&game[i][j]);
			}
		}
		char inter[r][c];
		LOOP {
			LOOP1 {
				char ch=game[i][j];
				if(i==0){
					if(j==0) {
						if(ch==A) {
							
						}
					}
				}
			}
		}
	}
	
}
