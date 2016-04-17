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
			int count=2;
			while(r<c) {
				r+=(1/count);
				count++;
			}
			printf("%d card(s)",--count);
				
			}
		}
		return 0;
	}

