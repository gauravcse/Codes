#include<stdio.h>

struct complex {
	float real;
	float imaginary;
};
struct complex add(struct complex,struct complex);
int main(void) {
	struct complex m,n,sum;
	printf("ENTER THE COMPLEX NUMBERS\n");
	scanf("%f %f",&m.real,&m.imaginary);
	scanf("%f %f",&n.real,&n.imaginary);
	sum=add(m,n);
	if(sum.real!=0.0) {
		if(sum.imaginary>0.0)
		  printf("%.5f + j%0.5f",sum.real,sum.imaginary);
		else if(sum.imaginary<0.0) 
		  printf("%0.5f - j%.5f",sum.real,(-sum.imaginary));
		else 
		  printf("%.5f",sum.real);
	}
	else {
		if(sum.imaginary<0) 
		  printf("- j%.5f",sum.real,(-sum.imaginary));
		else if(sum.imaginary>0)
		  printf("j%.5f",sum.imaginary);
		else 
		  printf("0.5f",sum.real);
		
	}
	return 0;	
}
struct complex add(struct complex a,struct complex b) {
	struct complex sum1;
	sum1.real=a.real+b.real;
	sum1.imaginary=a.imaginary+b.imaginary;
	return sum1;
}

