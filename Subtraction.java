class Subtraction
{
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



