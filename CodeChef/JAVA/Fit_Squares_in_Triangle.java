import java.io.*;
class Fit_Squares_in_Triangle {
    public static void main(String args[]) {
        try {
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            int t=Integer.parseInt(br.readLine());
            while(t>0) { 
                int n=Integer.parseInt(br.readLine());
                if(n<=3) {
                    System.out.println("0");
                    break;
                }
                else {
                    n=n-3;
                    int k=1;
                    int count=2;
                    while(n-->=0) {
                        if(n==0) {
                             System.out.println(k);
                             break;
                        }
                        --n;
                        if(n==0) {
                             System.out.println(k);
                             break;
                        }
                        else {
                            k=k+count;
                            count++;
                           
                        }
                    }
                }
                t--;
            }
        }
        catch(IOException e) {
             System.out.println(e.toString());
        }
        catch(NumberFormatException e) {
             System.out.println(e.toString());
        }
    }
}