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

int a,b,c;

double f(double x) {
	return ((a*x)+(b*sin(x))-c);
}

int main(void) {
	T;
	TD;
	TEST {
		scanf("%d %d %d",&a,&b,&c);
		double A,B;
		A=0;
		B=100000;
		double mid=50000.0;
		int count=1;
		do {
			double f_mid=f(mid);
			if(f_mid*f(A)<0) {
				B=mid;
			}
			else if(f_mid*f(B)<0)
				A=mid;
			//printf("%d %0.6f %0.6f %0.6f\n",count++,A,B,mid);
			mid=(A+B)/2;
		} while(fabs(A-B)>0.0000001);
		printf("%0.6f\n",mid);
	}
	
}
