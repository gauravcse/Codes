import java.io.*;
class fact
{
    public static void main()throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        
            int arr[]=new int[t];
            for(int i=1;i<=t;i++)
            {
                arr[i]=Integer.parseInt(br.readLine());
                if(arr[i]<=100)
                System.out.println(arr[i]);
                else
                arr[i]=0;
                
            }
            long ar[]=new long[t];
            for(int i=1;i<=t;i++)
            {
                ar[i]=1;
                for(int j=2;j<=arr[i];j++)
                {
                    ar[i]*=j;
                }
            }
            for(int i=1;i<=t;i++)
            {
                System.out.println(ar[i]);
            }
        }



    }

    
    
    
                