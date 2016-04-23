import java.io.*;
import java.util.Scanner;
class Begin_End {
    public static void main(String args[])throws IOException  {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String s=sc.next();
        int f=n;
        char ch[]=s.toCharArray();
        for(int i=2;i<n;i++) {
            for(int j=0;j<=(n-i);j++) {
                if(ch[j]==ch[j+i-1]) {
                    f++;
                }
            }
        }
        if(ch[0]==ch[n-1]) 
            f++;
        System.out.println(f);
    }
}
    