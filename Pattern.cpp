#include<stdio.h>
int main() {
	int n;
	scanf("%d",&n);
	int flag=n-2;
	int num;
   	num=(int)((n/2)+1);
   for(int i=1;i<=num;i++) {
   	  
   	  for(int j=1;j<=i;j++) {
   	  	 if(j%2==1)
   	  	   printf("1");
   	  	 else
   	  	   printf("0");
         }
      for(int j=1;j<=flag;j++)
         printf(" ");
      flag-=2;
       for(int j=1;j<=i;j++) {
   	  	 if(j%2==1)
   	  	   printf("1");
   	  	 else
   	  	   printf("0");
         }
         printf("\n");
   }
   return 0;
}
