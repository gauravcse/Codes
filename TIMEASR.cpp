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

float time[12][60];

void time_calculate() {
	for(int i=0;i<12;i++) {
		for(int j=0;j<60;j++) {
			time[i][j]=fabs(30*i-5.5*j);
			if(time[i][j]>180)
				time[i][j]=360-time[i][j];
		}
	}
}

int main(void) {
	T;
	TD;
	time_calculate();
	/*for(int i=0;i<12;i++) {
		for(int j=0;j<60;j++) {
			printf("%0.4f	",time[i][j]);
		}
	}*/
	TEST  {
		float n;
		scanf("%f",&n);
		//float eps=1.0/120.0;
		/*if((round(n)-n)>0 && (round(n)-n)<=0.25)
			n=round(n);
		else if((n-round(n))>0 && (n-round(n))<=0.25)
			n=round(n);
		else if((n-(int)n)!=0)
			n=(int)n+0.5;*/
		//int count=0;
		int flag=0;
		if((n-(int)n)!=0.0)
			flag=1;
		double min=180;
		for(int i=0;i<12;i++) {
			for(int j=0;j<60;j++) {
				if(flag) {
					if(fabs(n-time[i][j])<)
						min=time[i][j];
				};
				if(fabs(n-time[i][j])==0) {
					printf("%02d:%02d\n",i,j);
					
					//printf("%0.4f  ",time[i][j]);
					//count++;
				}
				//printf("%0.4f  ",time[i][j]);
			}
			//printf("\n");
		/*	if(count==2)
				break;*/
		}
		if(flag) {
			for(int i=0;i<12;i++) {
				for(int j=0;j<60;j++) {
					if(min==time[i][j])
						printf("%02d:%02d\n",i,j);
				}
			}
		}
	}
	
}
