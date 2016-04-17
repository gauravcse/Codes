#include<stdio.h>
int* add(int* x,int* y);
int main() {
	int a[]={2,4,6};
	int b[]={3,5,1};
	int* s;
	int z=3;
	*s=add(*a,*b,z,z);
	for(int i=0;i<3;i++){
	printf("%d",s[i]);
}
}






int* add(int* x,int* y,int l1,int l2) {
	int* sum;
//	int l1=3;int l2=3;
//	int sc=l1;
	int flag=0;
	int c=l2-1;
	while(c>=0) {
		sum[l1]=(x[l1-1]+y[l2-1]+flag)%10;
	//	flag=0;
		l1--;
		l2--;
		c--;
		if((x[l1-1]+y[l2-1]+flag)>9)
		  flag=1;
		else
		flag=0;
	}
	return sum;
}

