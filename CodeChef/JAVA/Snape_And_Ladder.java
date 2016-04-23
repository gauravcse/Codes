import java.util.Scanner;
//import java.Math;
class Snape_And_Ladder {
    public static void main(String args[])throws NumberFormatException {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0) {
            t--;
            int b=sc.nextInt();
            int ls=sc.nextInt();
            double max=(Math.sqrt(Math.pow(b,2)+Math.pow(ls,2)));
            double min=Math.sqrt(Math.abs(Math.pow(b,2)-Math.pow(ls,2)));
            System.out.println(min+" "+max);
        }
    }
}

            
            