import java.util.Scanner;
class Mcoins {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int k=sc.nextInt();
        int l=sc.nextInt();
        int m=sc.nextInt();
        int arr[]=new int[m];
        int max=0;
        for(int i=0;i<m;i++) {
            arr[i]=sc.nextInt();
            if(arr[i]>=max) 
                max=arr[i];
        }
        boolean memo[]=new boolean[max+l+k];
        memo[0]=false;
        memo[1]=memo[l]=memo[k]=true;
        for(int i=1;i<max;i++) {
            if(!memo[i]) {
                memo[i+1]=memo[i+l]=memo[i+k]=true;
            }
        }

        for(int i=0;i<m;i++){
            if(memo[arr[i]]) 
                System.out.print("A");
            else
                System.out.print("B");
        }
    }
}
        