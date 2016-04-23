import java.util.Scanner;
import java.lang.Math;
class Party {
    public static int dp[][];
    public static int keep[][];
    public static int w[]; // Weight Equivalent. Money in this case
    public static int p[]; // Fun equivalent. To be maximised

    public static int Knapsack(int n,int W) {
        if(n==0)
            return 0;        
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=W;j++) {
                if(w[i]<=j) {
                    dp[i][j]=Math.max(dp[i-1][j],p[i]+dp[i-1][j-w[i]]);
                    if(dp[i][j]!=dp[i-1][j])
                        keep[i][j]=1;
                }
                else { 
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int W,n;
        do {
            W=sc.nextInt();
            n=sc.nextInt();
            if(W==0 && n==0)
                break;
             /*   else if(W==0)
                System.out.println("1 0");*/
            w=new int[n+1];
            p=new int[n+1];
            for(int i=1;i<=n;i++) {
                w[i]=sc.nextInt();
                p[i]=sc.nextInt();
            }
            if(W==0) {
                for(int i=1;i<=n;i++) {
                    int count=0;
                    int ent=0;
                    if(w[i]==0) {
                        count+=p[i];
                    }
                    System.out.println("0 "+count);
                    continue;
            }
            }
            dp=new int[n+1][W+1];
            keep=new int[n+1][W+1];
            for(int i=0;i<=W;i++)
                dp[0][i]=0;
                
            for(int i=0;i<=n;i++)
                dp[i][0]=0;
            int ans=Knapsack(n,W);
            int sum=0;
            for(int i=n;i>=1;i--) {
                if(keep[i][W]==1 && W-w[i]>=0) {
                    sum+=w[i];
                    W-=w[i];
                }
                if(W==0)
                    break;
            }
            System.out.println(sum+" "+ans);
        } while(true);
    }
}