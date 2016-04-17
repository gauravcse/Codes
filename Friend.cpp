#include<stdio.h>
#include<stdlib.h>
int main() {
	while(1) {
		float c;
		scanf("%f",&c);
		if(c==0.00)
		  exit(0);
		else if((c>=0.01)&&(c<=5.20)) {
			float r=0.0;
			float count=2.0;
			while(r<c) {
				r+=(1.0/count);
				count=count+1.0;
			}
			int count1=(int)(count-2.0);
			printf("%d card(s)\n",count1);
				
			}
		}
		return 0;
	}

