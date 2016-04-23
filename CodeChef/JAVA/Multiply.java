import java.io.*;
import java.math.BigInteger;
class Multiply {
    public static void main(String args[])throws IOException  {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int c=Integer.parseInt(br.readLine());
            while(c>0) {
                BigInteger b1=new BigInteger(br.readLine());
                BigInteger b2=new BigInteger(br.readLine());
                System.out.println(b1.multiply(b2));
                c--;
            }
    } 
}