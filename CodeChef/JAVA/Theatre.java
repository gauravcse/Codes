import java.util.Scanner;

public class Theatre {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        long t=sc.nextLong();
        while(t>0) {
            t--;
            long product=1;
            final long mod=1000000007;
            int n=sc.nextInt();
            int arr[]=new int[n];
            for(int i=0;i<n;i++) {
                arr[i]=sc.nextInt();
            }
            Stacks stack=new Stacks(n);
            stack.push(arr[n-1]);
            int count=n;
            while(count>0) {
                count--;
                int flag=0;
                int num=stack.top;
                for(int i=0;i<=num;i++) {
                    // System.out.println("arr[count] is "+ arr[count] +"And peek is "+stack.peek()+" and top"+stack.top);
                    if(arr[count]<stack.peek()&& !stack.isEmpty()) {
                        flag++;
                        product=(product*stack.peek())%mod;
                        //System.out.println("Updated product"+product);
                        stack.push(arr[count]);
                        break;
                    }
                    else if(arr[count]>stack.peek() || stack.isEmpty()) {
                        stack.pop();
                    }
                }
                if(flag==0) {
                    stack.push(arr[count]);
                }
            }
            System.out.println(product);

        }
    }
}

                        