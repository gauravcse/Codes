import java.io.*;
import java.util.Scanner;
class Forgotten {
    public static void main(String args[])throws IOException {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0) {
            t--;
            int n=sc.nextInt();
            int k=sc.nextInt();
            String f[]=new String[n];
            for(int i=0;i<n;i++) 
                f[i]=sc.next();
            String words[]=new String[2500];
            int count=0;
            while(k>0) {
                k--;
                int p=sc.nextInt();
                for(int i=count;i<(count+p);i++) {
                    words[i]=sc.next();
                }
                count+=p;
            }
            for(int i=0;i<n;i++) {
                boolean flag=false;
                for(int j=0;j<count;j++) {
                    if(f[i].equals(words[j])==true) {
                        System.out.print("YES ");
                        flag=true;
                        break;
                    }
                }
                if(!flag) {
                    System.out.print("NO ");
                }
            }
            System.out.println();
        }
    }
}
                    
    