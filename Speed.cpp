#include<stdio.h>
int main() {
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
	    if(((s1>0)&&(s2>0))||((s1<0)&&(s2<0))) {
		    printf("1");
	    }
	    else
	        printf("2");
	    printf("\n");
	}
	return 0;
}
