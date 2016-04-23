import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++) {
            arr[i]=sc.nextInt();
        }
		int low[]=new int[m];
		int high[]=new int[m];
		int max[]=new int[m];
		for(int i=0;i<m;i++) {
			high[i]=low[i]=max[i]=0;
		}
		int count=0,current=0;
        while(m>0) {
			int maxi=0,flag=0,ans=0;
            m--;
            int l=sc.nextInt();
            int u=sc.nextInt();
			low[count]=l;
			high[count]=u;
			current=count;
			//System.out.println(current);
			count++;
			for(int i=0;i<=current;i++) {
				//System.out.println(l+" "+low[i]+" "+u+" "+high[i]);
				if(l>low[i] && u<high[i]) {
					maxi=max[i];
					flag=1;
					//System.out.print("This is Entered");
				}
			}
			if(flag==1)
				ans=Answer(arr,l,u,maxi);
			else {
				maxi=Maximum(arr,l,u);
				//System.out.print("This is Entered");
				max[current]=maxi;
				ans=Answer(arr,l,u,maxi);
			}
            System.out.println(ans);
        }
    }
    
    public static int Answer(int array[],int low,int up,int max) {
        //int max=Maximum(array,low,up);
        int count=0;
        low--;
        up--;
        for(int i=low;i<=up;i++) {
            if(array[i]==max)
                count++;
        }
        return count;
    }
    
    public static int Maximum(int array[],int low,int up) {
        int max=array[--low];
        --up;
        for(int i=low;i<=up;i++) {
            if(array[i]>max) {
                max=array[i];
            }
        }
        return max;
    }
}