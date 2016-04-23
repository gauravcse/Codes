import java.util.*;
class ACM14KN3 {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>=0) {
            t--;
            String s=sc.next();
            long p=sc.nextLong();
            long q=sc.nextLong();
            long alpha[]=new long[26];
            for(int i=0;i<26;i++)
                alpha[i]=0;
            for(int i=0;i<s.length();i++) {
                int num=(int)s.charAt(i);
                num-=97;
                alpha[num]++;
            }
            for(int i=0;i<26;i++)
                alpha[i]*=p;
            long sum[]=new long[26];
            sum[0]=alpha[0];
            for(int i=1;i<26;i++)
                sum[i]=alpha[i]+sum[i-1];
           /* for(int i=0;i<26;i++)
                System.out.print(sum[i]+"   ");*/
            for(long i=0;i<q;i++) {
                long n=sc.nextLong();
                int j=0;
                if(n>sum[25]) {
                    System.out.println("-1");
                    continue;
                }
                else {
                    while(sum[j]<n) {
                        j++;
                    }
                    System.out.println((char)(j+97));
                }
            }
        }
    }
}