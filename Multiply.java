import java.io.*;
import java.math.BigInteger;
class Multiply {
    public static void main()throws IOException  {
        try {
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    int c=Integer.parseInt(br.readLine());
    System.out.println();
        while(c>0) {
        BigInteger b1=new BigInteger(br.readLine());
        System.out.println();
        BigInteger b2=new BigInteger(br.readLine());
        System.out.println();
        if(((b1.toString()).length()<=10000)&&((b2.toString()).length()<=10000)) {
            System.out.println(b1.multiply(b2));
        }
        c--;

    }
}
catch(NumberFormatException e) {
    return;
}
 catch(IOException e) {
    return;
}

}
}