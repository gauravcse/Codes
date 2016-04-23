import java.util.Scanner;
class Good_Joke {
    public static void main(String args[]) {
        try {
            Scanner sc=new Scanner(System.in);
            int t=sc.nextInt();
            while(t>0) {
                int n=sc.nextInt();
                for(int i=1;i<=n;i++) {
                    int p=sc.nextInt();
                    int q=sc.nextInt();
                    System.out.println();
                }
                int result=0;
                for(int i=1;i<=n;i++) {
                    result^=i;
                }
                System.out.println(result);
                t--;
            }
        }
        catch(NumberFormatException e) {
            System.out.println(e.toString());
        }
    }
}