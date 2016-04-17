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
	TEST {
		int n,m;
		scanf("%d %d",&n,&m);
		double sum=0.0;
		if(n==1) {
			sum=m;
			printf("%f\n",sum);
			continue;
		}
		else if(m==1){
			sum=n;
			printf("%f\n",sum);
			continue;
		}
		double arr[n][m];
		arr[0][0]=1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(i==0 & j==0)
					continue;
				if(i==0) {
					arr[i][j]=1.0/(float)pow(2,j);
					continue;
				};
				if(j==0) {
					arr[i][j]=1.0/(float)pow(2,i);
					continue;
				};
				if(i==n-1) {
					arr[i][j]=arr[i][j-1]+(0.5)*arr[i-1][j];
					continue;
				}
				if(j==m-1) {
					arr[i][j]=arr[i-1][j]+0.5*arr[i][j-1];
					continue;
				};
				arr[i][j]=0.5*(arr[i-1][j]+arr[i][j-1]);
			}
		}
		arr[n-1][m-1]=1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++)
				sum+=arr[i][j];	
		}
		printf("%f\n",sum);
		
	}	
	
}
