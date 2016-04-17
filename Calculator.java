import java.io.*;
class Calculator
{
    public void main(int T)throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        
        if(T<1000)
        {
            String arr[]=new String[T+1];
            for(int i=1;i<=T;i++)
            {
                arr[i]=br.readLine();
            }
            for(int i=1;i<=T;i++)
            {
                int n,m;//storing numbers
                n=m=0;
                char ch=' ';
                String s=arr[i];
                ch=operation(s);//+ - *
                n=first(s);//first digits   
                m=last(s);//last digits
                if(ch=='+')
                add(n,m);
                else if(ch=='-')
                subtract(n,m);
               
                System.out.print("----------------------------------------------");
                System.out.println();
            }
        }
        else
        {
            System.out.println("Invalid Input");
        }
    }
    public char operation(String s)
    {
        int l=s.length();
        char c=' ';
        for(int i=0;i<l;i++)
        {
            c=s.charAt(i);
            if((c=='+')||(c=='-'))
            {
                break;
            }
        }
        return c;
    }
    int first(String s)
    {
        int l=s.length();
        String st="";
        int n=0;
        for(int i=0;i<l;i++)
        {
            char c=s.charAt(i);
            
            if((c=='+')||(c=='-'))
            {
                n=Integer.valueOf(st);
                break;
            }
            else
            {
                st=st+c;
            }
        
        }
        return n;
    
    }
    int last(String s)
    {
        int l=s.length();
        String st="";
        int pos=0;
        for(int i=0;i<l;i++)
        {
            char c=s.charAt(i);
            if((c=='+')||(c=='-'))
            {
                pos=i;
                break;
            }
        }
        st=s.substring(pos,l);
        int m=Integer.valueOf(st);
        return m;
    }
        
public void add(int a,int b)
    {
        int da,db;
        da=db=0;
        int n=a;
        int m=b;
        while(n>0)
        {
            n=n/10;
            da++;
        }
        while(m>0)
        {
            m=m/10;
            db++;
        }
        if(da>db)
        {
            int d=da-db;
            System.out.println(" "+a);
            System.out.print("+");
            for(int i=1;i<=(d);i++)
            {
                System.out.print(" ");
            }
            System.out.println(b);
            for(int i=1;i<=(da+1);i++)
            {
                System.out.print("_");
            }
            System.out.println();
        }
        else if(da<=db)
        {
           int d=db-da;
           for(int i=1;i<=(d+1);i++)
            {
                System.out.print(" ");
            }
            System.out.println(a);
            System.out.println("+"+b);
            for(int i=1;i<=(db+1);i++)
            {
                System.out.print("_");
            }
            System.out.println();
        }
        int add=a+b;
        int dig=0;
        int ad=add;
        while(ad>0)
        {
            ad/=10;
            dig++;
        }
        int max=da>db?da:db;
        if(dig==max)
        System.out.print(" "+add);
        else
        {
          System.out.print(add); 
    }

}
public void subtract(int a,int b)
    {
        int da,db;
        da=db=0;
        int n=a;
        int m=b;
        while(n>0)
        {
            n=n/10;
            da++;
        }
        while(m>0)
        {
            m=m/10;
            db++;
        }
        if(da>db)
        {
            int d=da-db;
            System.out.println(" "+a);
            System.out.print("+");
            for(int i=1;i<=(d);i++)
            {
                System.out.print(" ");
            }
            System.out.println(b);
            for(int i=1;i<=(da+1);i++)
            {
                System.out.print("_");
            }
            System.out.println();
        }
        else if(da<=db)
        {
           int d=db-da;
           for(int i=1;i<=(d+1);i++)
            {
                System.out.print(" ");
            }
            System.out.println(a);
            System.out.println("-"+b);
            for(int i=1;i<=(db+1);i++)
            {
                System.out.print("_");
            }
            System.out.println();
        }
        int sub=a-b;
        int sb=Math.abs(sub);
        int dig=0;
        while(sb>0)
        {
            sb=sb/10;
            dig++;
        }
        int max=da>db?da:db;
        int dif=(max-dig);
        if(a<b)
        {
        for(int i=1;i<=dif;i++)
        {
            System.out.print(" ");
        }
        System.out.print(sub);
    }
    else
    {
        for(int i=1;i<=(dif+1);i++)
        {
            System.out.print(" ");
        }
        System.out.print(sub);
    }

}
}


    
        
            
        