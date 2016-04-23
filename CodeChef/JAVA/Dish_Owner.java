import java.util.Scanner;
public class Dish_Owner {
    
    private static int arr[];
    //private static int len[];
    private static int score[];
    
    public static void Union(int a,int b) {
        int x=root(a);
        int y=root(b);
        if(score[x]>score[y]) {    arr[y]=arr[x];  /*len[x]+=len[y]; */score[x]+=score[y]; }
        else if(score[y]>score[x]) {  arr[x]=arr[y];  /*len[y]+=len[x]; */ score[y]+=score[x];}
    }
    
    public static boolean isConnected(int a,int b) {
        return root(a)==root(b);
    }
    
    public static int root(int x) {
        int y;
        if(arr[x]==x) 
            return x;
        else    {
            y=root(arr[x]);
            root[x]=y;
            return y;
        }
    }
    
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0) {
            t--;
            int n=sc.nextInt();
            arr=new int[n+1];
            score=new int[n+1];
            for(int i=1;i<=n;i++) {
                arr[i]=i;
                //len[i]=1;
                score[i]=sc.nextInt();
            }
            int q=sc.nextInt();
            while(q>0) {
               q--;
               int decision,a,b;
               decision=sc.nextInt();
               if(decision==0) {
                   a=sc.nextInt();
                   b=sc.nextInt();
                   if(isConnected(a,b)) {   System.out.println("Invalid query!");;   }
                   else {  Union(a,b); }
               }
               else {
                   a=sc.nextInt();
                   System.out.println(arr[a]);
               }
            }
        }
    }
}
