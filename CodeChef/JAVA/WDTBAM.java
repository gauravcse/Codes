import java.util.Scanner;
class WDTBAM {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0) {
            t--;
            int n=sc.nextInt();
            //char wa[]=new char[n];
            //char ca[]=new char[n];
            String was=sc.next();
            String cas=sc.next();
            int win[]=new int[n+1];
            for(int i=0;i<=n;i++) {
                win[i]=sc.nextInt();
            }
            int count=0;
            for(int i=0;i<n;i++){
                //wa[i]=;
                //ca[i]=;
                if(was.charAt(i)==cas.charAt(i))
                    count++;
            }
            if(count==n) {
                System.out.println(win[n]);
                continue;
            }
            else if(count==0) {
                System.out.println(win[0]);
                continue;
            }
            int max=win[0];
            for(int i=1;i<=count;i++) {
                if(win[i]>max)
                    max=win[i];
            }
            System.out.println(max);
        }
    }
}
            