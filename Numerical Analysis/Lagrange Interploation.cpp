/* 
Name of Author : Gaurav Mitra
*/
						
						/* LU Decomposition for solving linear equations*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>

int main(void)
{
    int n,i,k,j,p;
    double sum=0.0;
    float arr[10][10],arrL[10][10]={0},arrU[10][10]={0};
	double b[10],z[10],x[10];
	
	for(int i=0;i<10;i++) {
		b[i]=z[i]=x[i]=0;
	}
    
   printf("ENTER THE ORDER OF THE MATRIX \n");
    scanf("%d",&n);
    printf("ENTER THE COEFFICIENTS OF THE COEFFICIENT MATRUX IN ROW MAJOR\n ");
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++)
            scanf("%d",&arr[i][j]);
    }
    printf("ENTER THE ELEMENTS OF B \n");
    for(i=1;i<=n;i++)
       scanf("%d",&b[i]);
    				// LU DECOMPOSIION
    for(k=1;k<=n;k++) {
        arrU[k][k]=1;
        for(i=k;i<=n;i++) {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=arrL[i][p]*arrU[p][k];
            arrL[i][k]=arr[i][k]-sum;
        }

        
        for(j=k+1;j<=n;j++) {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=arrL[k][p]*arrU[p][j];
            arrU[k][j]=(arr[k][j]-sum)/arrL[k][k];
        }
    } 
    printf("LU matrix is \n");
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++)
            printf("%d",arrL[i][j]);
            printf("\n");
       
    }
    printf("\n");
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++)
           printf("%d",arrU[i][j]);
           printf("\n");
    }
    for(i=1;i<=n;i++) {                                        //forward subtitution method
        sum=0;
        for(p=1;p<i;p++)
        sum+=arrL[i][p]*z[p];
        z[i]=(b[i]-sum)/arrL[i][i];
    }
    for(i=n;i>0;i--) {
        sum=0;
        for(p=n;p>i;p--)
            sum+=arrU[i][p]*x[p];
        x[i]=(z[i]-sum)/arrU[i][i];
    }
    printf("Set of solution is\n");
    for(i=1;i<=n;i++)
        printf("%d ",x[i]);
    return 0;
}
