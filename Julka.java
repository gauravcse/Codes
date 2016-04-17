import java.io.*;
import java.math.BigInteger;
class Julka {
    public static void main(String []args)throws IOException{
        try {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int count=10;
        while(count--!=0) {
            BigInteger a=new BigInteger(br.readLine());
            System.out.println();
            BigInteger b=new BigInteger(br.readLine());
            System.out.println();
            BigInteger x=a.subtract(b);
            BigInteger z=new BigInteger("2");
            x=x.divide(z);
            BigInteger y=x.add(b);
            System.out.println(y);
            System.out.println(x);
        }
    } 
    catch(NumberFormatException e) {
       return;
    }
        
    
}
}
