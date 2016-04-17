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

/*int cmpfnc(const void* a,const void* b) {
	return (*(int*)a-*(int)*b);
}*/

int main(void) {
	int n,u;
	scanf("%d %d",&n,&u);
	int arr[n];
	
	int i;
	for(i=0;i<n;i++)
		arr[i]=0;
	while(u--) {
		int a,b;
		scanf("%d %d",&a,&b);
		for(i=b-1;i<n;i+=a)
			arr[i]++;
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
