#include<stdio.h>
#include<math.h>
#define eps 1.0/120
int main(){
	int t,i,j;
	scanf("%d",&t);
	double time[12][60];
	for(i=0;i<12;i++){
		for(j=0;j<60;j++)
		time[i][j]=fabs((double)(i*30)+(double)(j*.5)-(double)(j*6));
		}
	for(i=0;i<12;i++){
		for(j=0;j<60;j++)
		if(time[i][j]>180){
			time[i][j]=(double)(360)-time[i][j];
		}
		}
	
	
	while(t--)
	{
		double n;
		int hh,mm,hh1,mm1;
		scanf("%lf",&n);
		if(n==180){
			printf("06:00\n");
		}
		else if(n==0)
		printf("00:00\n");
		else if(n!=180 && n!=0){
			int flag=0;
	for(i=0;i<12;i++){
		for(j=0;j<60;j++){
			if(fabs(time[i][j]-(n))<eps){
				hh=i;
				mm=j;
			printf("%.2d:%.2d\n",hh,mm);	
				
			
			}
			
		}
		
	}
	
}
}
return 0;
} 
