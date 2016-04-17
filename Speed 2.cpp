#include<stdio.h>
#include<math.h>
int great(int x,int y);
int main()  {
	int t;
	scanf("%d",&t);
	printf("\n");
	while(t--) {
	    line:
		int s1,s2;
		scanf("%d %d",&s1,&s2);
		printf("\n");
		if((s1==0)||(s2==0)) {
			goto line;
		}
		int s3=abs(s1-s2);
		int gcd=great(abs(s1),abs(s2));
		printf("%d \n",(s3/gcd));
	}
	return 0;
		
}
int great(int x,int y)  {
	int max=x>=y?y:x;
	do {
		if((x%max==0)&&(y%max==0))	
		   break;
	} while(--max);
	return max;
}
