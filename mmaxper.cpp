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


LLU compare(LLU left, LLU right){
	if(left>right) {
		return (-1*right);
	}
	else if(right>left) {
		return (right-2*left);
	}
	else {
		return (-1*left);
	}
}

LLU max(LLU left,LLU right) {
	if(left>=right)
		return left;
	else
		return right;
}

struct pair {
	LLU a;
	LLU b;
};

int main(void) {
	N;
	ND;
	struct pair arr[n+5];
	struct pair results[n+5];
	for(int i=0;i<n;i++) {
		scanf("%llu %llu",&arr[i].a,&arr[i].b);
		results[i].a=results[i].b=0;
	}
	results[0].a=results[0].b=(arr[0].a+arr[0].b);
	for(int i=1;i<n;i++) {
		LLU up1,up2;
		LLU down1,down2;
		LLU sum=arr[i].a+arr[i].b;
		LLU sumup=sum+results[i-1].a;
		LLU sumdown=sum+results[i-1].b;
		up1=compare(arr[i-1].a,arr[i].a);
		up2=compare(arr[i-1].b,arr[i].a);
		down1=compare(arr[i-1].a,arr[i].b);
		down2=compare(arr[i-1].b,arr[i].b);
		results[i].a=max(up1+sumup,up2+sumdown);
		results[i].b=max(down1+sumup,down2+sumdown);
		//printf("%llu 	%llu\n",results[i].a,results[i].b);
	}
	if(results[n-1].a>results[n-1].b) {
		printf("%llu",results[n-1].a-arr[n-1].a);
	}
	else if(results[n-1].a<results[n-1].b) {
		printf("%llu",results[n-1].b-arr[n-1].b);
	}
	else {
		printf("%llu",max(results[n-1].a-arr[n-1].a,results[n-1].b-arr[n-1].b));
	}
}
