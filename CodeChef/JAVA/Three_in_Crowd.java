import java.io.*;
import java.util.Scanner;
import java.lang.Math;
class Three_in_Crowd {
    public static void main(String args[]) {
        try {
            Scanner sc=new Scanner(System.in);
            int t=sc.nextInt();
            while(t>0) {
                t--;
                int n=sc.nextInt();
                //Solution is 2^n-f(n)
                switch(n) {
                    case 1 : System.out.println("0");
                             break;
                    case 2 : System.out.println("0");
                             break;
                    case 3 : System.out.println("1");
                             break;
                    default :
                            long A[][]={ {1,1,1} , {1,0,0}, {0,1,0} };
                            long B[][]=new long[3][3];
                            B=Matrix_Exp(A,n-3);
                            double number=(Math.pow(2,n));
                            double ans=((7*B[0][0]+4*B[0][1]+2*B[0][2]));
                            System.out.println((number-ans)%1000000007);
                            break;
                        }
                    }
                }
        catch(NumberFormatException e) {
           System.out.println(e.toString());
        }
    }
    public static long[][] Matrix_Mult(long A[][],long B[][]) {
        long C[][]={{0,0,0},{0,0,0},{0,0,0}};
        for(int i=0;i<=2;i++) {
            for(int j=0;j<=2;j++) {
                for(int k=0;k<=2;k++) {
                    C[i][j]+=(A[i][k]*B[k][j])%1000000007;
                }
            }
        }
        return C;
    }
    public static long[][] Matrix_Exp(long A[][],long t) {
        if(t==1) 
            return A;
        else if(t%2==0) {
            long A1[][]=new long[3][3];
            A1=Matrix_Exp(A,t/2);
            return (Matrix_Mult(A1,A1));
        }
        else {
            return (Matrix_Mult(A,Matrix_Exp(A,t-1)));
        }

    }
}
    
    