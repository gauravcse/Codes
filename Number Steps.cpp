#include<stdio.h>
int main()  {
	int N;
	scanf("%d",&N);
	printf("\n");
	while(N--) {
		int x,y;
		scanf("%d %d",&x,&y);
		if((x>=0)&&(x<=10000)&&(y>=0)&&(y<=10000))	{
			if((x==y)||(x==(y+2)))  {
				if((x%2!=0)&&(x==y)) {
					printf("%d\n",(2*x-1));
				}
				else if((x%2!=0)&&(x!=y))
				    printf("%d\n",(2*y+1));
				else {
					if(x==y)
					  printf("%d\n",2*x);
					else
					  printf("%d\n",(2*y+2));
				}
			}
			else {
				printf("No Number\n");
			}
		}
}
return 0;
}

