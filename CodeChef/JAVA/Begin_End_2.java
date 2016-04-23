import java.io.*;
import java.util.Scanner;
class Begin_End_2 {
    public static void main(String args[])throws IOException  {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String s=sc.next();
        long f=n;
        long alpha[]=new long[26];
        for(int i=0;i<26;i++) {
            alpha[i]=0;
        }
        for(int i=0;i<n;i++) {
            char ch=s.charAt(i);
            int pos=(int)ch;
            alpha[(pos-97)]++;
        }
        for(int i=0;i<26;i++) {
            if(alpha[i]==0 || alpha[i]==1)
                continue;
            else {
                long num=alpha[i]-1;
                f+=((num*(num+1))/2);
            }
        }
        System.out.println(f);
    }
}
             