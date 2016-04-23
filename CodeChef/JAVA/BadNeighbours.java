import java.io.*;
import java.lang.Math;
class BadNeighbours {    
    public static int maxDonations(int a[]) {
        int len=a.length;
        int dp[]=new int[len];
        dp[0]=a[0];
        dp[1]=(int)Math.max(dp[0],a[1]);
        for(int i=2;i<len;i++) {
            dp[i]=(int)Math.max((dp[i-2]+a[i]),dp[i-1]);
        }
        /*for(int i=0;i<len;i++)
            System.out.print(dp[i]+"\t");*/
        return (int)(Math.max((int)(Math.max(dp[len-2],(dp[len-1]-a[len-1]))),(dp[len-1]-a[0])));
    }
    
    public static void main(String args[])throws IOException {
        int arr[]=	{917, 19, 978, 687, 346, 245, 677, 708, 565, 940,
    211, 127, 993, 768, 469, 279, 460, 335, 734, 130, 691, 783, 182,
    391, 827, 295, 534, 263, 193, 498, 327, 120, 690
};
        System.out.println(maxDonations(arr));
    }
}