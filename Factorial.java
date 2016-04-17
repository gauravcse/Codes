import java.io.*;
class Factorial
{
    public static void main()throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter T numbers");
        int T=Integer.parseInt(br.readLine());
        int arr[]=new int[T];
        for(int i=0;i<T;i++)
        {
            arr[i]=Integer.parseInt(br.readLine());
        }
        int arres[]=new int[T];
        for(int i=0;i<T;i++)
        {
            int p=1;
            for(int j=2;j<=arr[i];j++)
            {
               p*=j;
            }
            int flag=0;
            while((p%10)==0)
            {
                flag++;
                p/=10;
            }
            arres[i]=flag;
        }
        for(int i=0;i<T;i++)
        {
            System.out.println(arres[i]);
    }
}
}



    
        