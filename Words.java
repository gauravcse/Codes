import java.io.*;
class Words {
    public int T;
    Words()throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the Number of Test Cases");
        T=Integer.parseInt(br.readLine());
    }
    public void main()throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        if(T<=500)
        {
            String prt[]=new String[T];
            for(int j=0;j<T;j++)
            {
            System.out.println("Enter the Number of Words");
            int n=Integer.parseInt(br.readLine());
            String arr[]=new String[n];
            int i=0;
            while(i<n)
            {
                arr[i]=br.readLine();
                i++;
            }
            boolean flag=true;
            for(i=0;i<(n-1);i++)
            {
                int l=arr[i].length();
                char ch=arr[i].charAt(l-1);
                if(ch!=arr[i+1].charAt(0))
                {
                    flag=false;
                }
            }
            if(flag==true)
            {
               prt[j]="Ordering is possible";
            }
            else 
            {
             prt[j]="The door cannot be opened";
            }
        }
        for(int j=0;j<T;j++)
        {
            System.out.print(prt[j]+"\n");
        }
}
}
}