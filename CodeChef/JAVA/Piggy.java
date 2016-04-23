import java.util.Scanner;
import java.lang.*;
import java.lang.Math;
class Piggy {
    
    static int p[];
    static int w[];
    static int dp[];
    
    public static int piggy(int W) {
        if(dp[W]!=1000000)
            return dp[W];
        else {
            for(int i=0;i<w.length;i++) {
                if(W>=w[i])
                    dp[W]=Math.min(dp[W],piggy(W-w[i])+p[i]);
            }
        }
        return dp[W];
    }
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0) {
            int e,f;
            e=sc.nextInt();
            f=sc.nextInt();
            int W=f-e;
            int n=sc.nextInt();
            p=new int[n];
            w=new int[n];
            for(int i=0;i<n;i++) {
                p[i]=sc.nextInt();
                w[i]=sc.nextInt();
            }
            dp=new int[W+1];
            for(int i=0;i<=W;i++)
                dp[i]=1000000;
            int ans=piggy(W);
            if(ans!=1000000)
                System.out.println("The minimum amount of money in the piggy-bank is "+ans+".");
            else
                System.out.println("This is impossible.");
        }
    }
}
            
            