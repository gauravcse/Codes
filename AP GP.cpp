#include<stdio.h>	
int main()  {
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	while(2)  {
		if ((a==0)&&(b==0)&&(c==0)) {
			break;
		}
		
		else if((a>=-10000)&&(a<=10000)&&(b>=-10000)&&(b<=10000)&&(c>=-10000)&&(c<=10000)) {
		if((2*b)==(a+c)) 
			printf("AP %d\n",(c+(b-a)));
		else if((b*b)==(a*c))
		    printf("GP %d\n",(c*(b/a)));
		}
	scanf("%d %d %d",&a,&b,&c);					
	}
	return 0;
}
