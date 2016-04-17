                            /* Jacobi Method for solving a system of linear simultaneous equation     */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void print_solution(float x[],int n) {
    printf("\nTHE SOLUTION OF THE EQUATIONS :\n");
    int i;
    for(i=1;i<=n;i++)
        printf("\t\tx[%d]=%f\n",i,x[i]);
}

float input() {
    
    float input;
    scanf("%f",&input);
    return input;
}

int error_check(float temp[],float x[],int n) {
    int i,flag=0;
    for(i=1;i<=n;i++){
		    if(fabs(temp[i]-x[i])>=0.000001){
			    flag=1;                         // Error Calculation
			    break;
		    }
    }
    return flag;
	    
}


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
			a[i][j]=input();                              // Coefficient Matrix
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
			x[i]=temp[i];               //      Copying it into the temporary matrix for error calculation and updating x only once
		}
	    printf("    %d     %0.5f       %0.5f       %0.5f\n",++count,temp[1],temp[2],temp[3]);
	    for(i=1;i<=n;i++){
		    sum=0;
		    for(j=1;j<=n;j++){
			    if(i!=j){
				    sum+=a[i][j]*x[j];      // Solving for the x ith term with respect to the rest x i's
			    }
		    }
		    temp[i]=(b[i]-sum)/a[i][i];
	    }
	    /*for(i=1;i<=n;i++){
		    if(fabs(temp[i]-x[i])>=0.000001){
			    flag=1;                        
			    break;
		    }
        } */
        flag=error_check(temp,x,n);
        if(flag==1)
            break;
 
	}while(flag==1);
	print_solution(temp,n);
	
}


