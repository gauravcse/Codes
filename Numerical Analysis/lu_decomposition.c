/************** LU Decomposition for solving linear equations ***********/
#include<stdio.h>

int main()
{
    int n,i,k,j,p;
    float a[10][10],l[10][10]={0},u[10][10]={0},sum,b[10],z[10]={0},x[10]={0};
    
   printf("Enter the order of the matrix\n");
    scanf("%d",&n);
    printf("Enter all coefficients of matrix :\n ");
    for(i=1;i<=n;i++)
    {
        //cout<<"\nRow "<<i<<"  ";
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter elements of b matrix\n");
    for(i=1;i<=n;i++)
       scanf("%d",&b[i]);
    //********** LU decomposition *****//
    for(k=1;k<=n;k++)
    {
        u[k][k]=1;
        for(i=k;i<=n;i++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[i][p]*u[p][k];
            l[i][k]=a[i][k]-sum;
        }

        
        for(j=k+1;j<=n;j++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[k][p]*u[p][j];
            u[k][j]=(a[k][j]-sum)/l[k][k];
        }
    }
    //******** Displaying LU matrix**********//
    printf("LU matrix is \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d",l[i][j]);
            printf("\n");
       // cout<<endl;
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
           printf("%d",u[i][j]);
           printf("\n");
        //cout<<endl;
    }

    //***** FINDING Z; LZ=b*********//

    for(i=1;i<=n;i++)
    {                                        //forward subtitution method
        sum=0;
        for(p=1;p<i;p++)
        sum+=l[i][p]*z[p];
        z[i]=(b[i]-sum)/l[i][i];
    }
    //********** FINDING X; UX=Z***********//

    for(i=n;i>0;i--)
    {
        sum=0;
        for(p=n;p>i;p--)
            sum+=u[i][p]*x[p];
        x[i]=(z[i]-sum)/u[i][i];
    }
    //*********** DISPLAYING SOLUTION**************//
    printf("Set of solution is\n");
    for(i=1;i<=n;i++)
        printf("%d ",x[i]);

    return 0;
}
