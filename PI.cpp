#include<stdio.h>
#include<math.h>
int main(void) {
	double PI=0.0;
	for(int count=1;count<100000;count++) {
	    if(count%2==0)
	      PI-=(double)1/(2*count-1);
	    else
          PI+=(double)1/(2*count-1);
        printf("%0.7f\n",PI);
	    
	}
	PI*=4;
	printf("%0.7f",PI);
}
