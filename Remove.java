import java.io.*;
class Remove {
    public static void main(String args[])throws IOException  {
          BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
          //int t=Integer.parseInt(br.readLine());
          //while(t!=0)  {
              int min=0;
              String x=br.readLine();
              String y=br.readLine();
              int lx=x.length();
              int ly=y.length();
              if((lx<=10000)&&(ly<=10000)) {
                  char ch=y.charAt(0);
                  int index=x.indexOf(ch);
                  while(index!=-1) {
                      String temp=x.substring(index+1,lx);
                      min++;
                      index=temp.indexOf(ch);
                  }
                  System.out.println(min);
              }
             // t--;
          }
    }

