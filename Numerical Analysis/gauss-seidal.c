                            /* Gauss Seidal Method for solving a system of linear simultaneous equation     */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(void){
	int n,i,j,flag;
	float **a,*b,*x,sum,*temp;
	printf("ENTER THE NUMBER OF SIMULTANEOUS EQUATIONS TO BE SOLVED: \n");
	scanf("%d",&n);                                     // Number of equations
	a=(float**)malloc(n*sizeof(float*));
	for(i=1;i<=n;i++){
		a[i]=(float*)malloc(n*sizeof(float));
	}
	b=(float*)malloc(n*sizeof(float));
	x=(float*)malloc(n*sizeof(float));
	temp=(float*)malloc(n*sizeof(float));
	printf("ENTER THE COEFICIENT MATRIX : \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%f",&a[i][j]);                               // Coefficient Matrix
		}
	}
	printf("ENTER THE RIGHT HAND SIDE OF THE MATRIX : \n");
	for(i=1;i<=n;i++){
		scanf("%f",&b[i]);
	}
	for(i=1;i<=n;i++){
		x[i]=0;
	}
	printf("Iteration    x[1]         x[1]          x[2]\n");
	int count=0;
	do{
		flag=0;
		for(i=1;i<=n;i++){
			temp[i]=x[i];               //Copying it into the temporary matrix for error calculation
		    }
	    printf("    %d     %0.5f       %0.5f       %0.5f\n",++count,temp[0],temp[1],temp[2]);
	    for(i=1;i<=n;i++){
		    sum=0;
		    for(j=1;j<=n;j++){
			    if(i!=j){
				    sum+=a[i][j]*x[j];      // Solving for the x ith term with respect to the rest x i's
			    }
		    }
		    x[i]=(b[i]-sum)/a[i][i];
	    }
	    for(i=1;i<=n;i++){
		    if(fabs(temp[i]-x[i])>=0.000001){
			    flag=1;                         // Error Calculation
			    break;
		    }
	    }
	}while(flag==1);
	printf("\nTHE SOLUTION OF THE EQUATIONS :\n");
	for(i=1;i<=n;i++){
		printf("\t\tx[%d]=%f\n",i,x[i]);
	}
}


