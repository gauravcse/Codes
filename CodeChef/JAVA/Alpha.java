import java.util.Scanner;
class Alpha {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        while(n>0) {
            n--;
            String str=sc.nextLine();
            String ans="";
            int len=str.length();
            for(int i=0;i<len;i++) {
                char ch=str.charAt(i);
                char c=' ';
                if(ch>=65 && ch<=90 || ch>=97 && ch<=122) {
                    if(ch==90 || ch==122) {
                        c=(char)(ch-25);
                        ans+=c;
                    }
                    else {
                        c=(char)(ch+1);
                        ans+=c;
                    }
                }
            }
            System.out.println(ans);
        }
    }
}