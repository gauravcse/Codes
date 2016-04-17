#include<stdio.h>
struct complex {
	float a;
	float b;
};
struct complex add(struct complex x,struct complex y);
int main() {
	struct complex x,y,sum;
	scanf("%f",&x.a);
	scanf("%f",&x.b);
	scanf("%f",&y.a);
	scanf("%f",&y.b);
	sum=add( x, y);
	if(sum.a!=0) {
		if(sum.b>0)
		  printf("THE SUM IS %f + i %f",sum.a,sum.b);
		else if(sum.b<0) {
		  printf("THE SUM IS %f - i %f",sum.a,-sum.b);	  
		}
		else
		  printf("THE SUM IS %f ",sum.a);
	}
	else {
		if(sum.b>0)
		  printf("THE SUM IS i %f",sum.b);
		else if(sum.b<0) {
		  printf("THE SUM IS - i %f",-sum.b);	  
		}
		else
		  printf("THE SUM IS %f ",sum.a);
	}
}
struct complex add(struct complex x,struct complex y) {
	struct complex s;
	s.a=x.a+y.a;
	s.b=x.b+y.b;
	return s;
}
