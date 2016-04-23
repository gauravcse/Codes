import java.util.Scanner;
import java.io.*;
import java.lang.Math;
class Edit {
    public static void main(String args[])throws IOException {
        Scanner sc=new Scanner(System.in);
        int t;
        t=sc.nextInt();
        while(t>0) {
            t--;
            String a,b;
            a=sc.next();
            b=sc.next();
            int la=a.length();
            int lb=b.length();
            int arr[][]=new int[la+5][lb+5];
            for(int i=0;i<=la;i++) {
                arr[0][i]=i;
            }
            for(int j=0;j<=lb;j++) {
                arr[j][0]=j;
            }
            for(int i=1;i<=la;i++) {
                for(int j=1;j<=lb;j++) {
                    if(a.charAt(i-1)!=b.charAt(j-1))
                        arr[i][j]=Math.min(Math.min((arr[i-1][j]+1),(arr[i][j-1]+1)),(arr[i-1][j-1]+1));
                    else
                        arr[i][j]=arr[i-1][j-1];
                }
            }
            System.out.println(arr[la][lb]);
        }
    }
}
