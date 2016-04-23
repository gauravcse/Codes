import java.util.Scanner;
class Version_Control_System {
    public static void main(String args[]) {
        try {
            Scanner sc=new Scanner(System.in);
            int t=sc.nextInt();
            boolean tracked[]=new boolean[101];
            boolean ignored[]=new boolean[101];
            for(int i=1;i<=100;i++ )
                tracked[i]=ignored[i]=false;
            while(t>=1) {
                int n,m,k;
                n=sc.nextInt();
                m=sc.nextInt();
                k=sc.nextInt();
                for(int i=1;i<=n;i++) {
                    int r=sc.nextInt();
                    tracked[r]=true;
                }
                for(int i=1;i<=n;i++) {
                    int r=sc.nextInt();
                    ignored[r]=true;
                }
                int both=0;
                int none=0;
                for(int i=1;i<=n;i++) {
                    if(tracked[i] && ignored[i])
                        both++;
                    else if(!tracked[i] && !ignored[i])
                        none++;
                }
                System.out.println(both+" "+none);
                t--;
            }
        }
        catch(NumberFormatException e) {
            System.out.println(e.toString());
        }
    }
}
