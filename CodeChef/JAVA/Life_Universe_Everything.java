import java.util.Scanner;
class Life_Universe_Everything {
    public static void main(String args[]) {
        try {
            Scanner sc=new Scanner(System.in);
            int num=sc.nextInt();
            while(num!=42) {
                System.out.println(num);
                num=sc.nextInt();
            }
        }
        catch (NumberFormatException e) {
            System.exit(0);
        }
    }
}
