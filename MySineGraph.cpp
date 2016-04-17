#include<stdio.h>
#include<math.h>
#define PI 3.14159265
#define HEIGHT 15
#define LENGTH 180
int main(void)  {
	float x=PI/2;
	for(;x>=0.0;x=x-0.1) {
		int k=(int)(ceil((HEIGHT*x)));
		for(int i=0;i<=k;i++) {
			printf(" ");
		}
		printf("*"); 
		for(int i=0;i<=((HEIGHT)*(PI-(2*x)));i++)
		    printf(" ");
		printf("*"); 
		
	}
	
	
	
}
