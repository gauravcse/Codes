#include<stdio.h>
#include<math.h>
int main() {
	printf("ENTER THE NUMBER ");
	int number;
	scanf("%d",&number);
	int root=sqrt(number);
	int n=number;
	int d=2;
	printf("\n%d = ",number);
	while(n%d==0) {
		printf("%d * ",d);
		n/=d;
	}
	if(n==1){printf("\b");return 0;}
	else {
		for(d=3;d<=root;d+=2) {
			while(n%d==0) {
				printf("%d * ",d);
				n/=d;
			}
		
		}
	}
}
