import java.util.Scanner;
public class Is_It_A_Tree {
    
    private static int arr[];
    private static int len[];
    
    public static void Union(int a,int b) {
        int x=root(a);
        int y=root(b);
        if(len[x]>=len[y]) {    arr[y]=arr[x];  len[x]+=len[y]; }
        else {  arr[x]=arr[y];  len[y]+=len[x]; }
    }
    
    public static boolean isConnected(int a,int b) {
        return root(a)==root(b);
    }
    
    public static int root(int x) {
        if(arr[x]==x) 
            return x;
        else    
            return root(arr[x]);
    }
    
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        arr=new int[n];
        len=new int[n];
        for(int i=0;i<n;i++) {
            arr[i]=i;
                len[i]=1;
        }
        int flag=0;
        while(m>0) {
            m--;
            int a=sc.nextInt();
            int b=sc.nextInt();
            if(isConnected(a-1,b-1)) {  flag=1; }
            else {  Union(a-1,b-1); }
        }
        if(flag==0) {   System.out.println("YES");  }
        else {   System.out.println("NO");  }
    }
}
            
            