#include<stdio.h>	
int checkrev(int *x,int *y,int len);
int main(void)  {
	int t;
	scanf("%d",&t);
	printf("\n");
	while(t--) {
	char ch;
	int a[1000];
	int count=0;
	while(ch=getchar()!='\n') {
		a[count++]=ch-'0';
	}
	//count is the length of the array
	int reverse[count];
	int flag;
	while(1) {
		flag=count-1;
		if(checkrev(a,reverse,count)==1){
			break;
		}
		else {
			a[flag]+=1;
			if(a[flag]==10) {
				do {
					a[flag]=0;
					--flag;
					a[flag]=a[flag]+1;
				}
				while(a[flag]==10);
				}
			}
			
			
		}
		for(flag=0;flag<count;flag++)
		   printf("%d",reverse[flag]);
	}
}
int checkrev(int *x,int *y,int len)	 {
	int i=len-1;
	int j=0;
	for(;i>=0;i--){
		y[j]=x[i];
		j++;
	}
	j=0;
	while(j<(len)){
		if(x[j]==y[j])
		   continue;
		else
		   return 0;
		j++;
	}
	return 1;
	
	}


