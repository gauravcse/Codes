import java.util.*;
import java.math.BigInteger;
class Palin {
    public static void main(String []args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        int count=1;
        while(count<t) {
          BigInteger a=sc.nextBigInteger();
          System.out.println();
          boolean flag=false;
          a=a.add(BigInteger.ONE);
          while(flag==false) {
              String s=""+a;
              StringBuffer sb=new StringBuffer(s);
              StringBuffer sb1=sb.reverse();
              String s1=sb1.toString();
              if(s1.equals(s)==true) {
                 flag=true;
                System.out.println(s);
            }
              else {
                     a=a.add(BigInteger.ONE);
                     continue;
                    }
                }
                count++;
            }
        }
    }
    
                  
              
              
        