import java.io.*;
import java.util.Scanner;

public class QuickSort {
	
	static int arr[];
	
	public static void swap(int i,int j) {
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	public static int Partition(int left,int right) {
		int P=arr[left];
		int j=left;
		for(int i=left;i<right;i++) {
			if(arr[i+1]>P) {
				//System.out.println("The swap is between "+arr[i+1]+" and "+arr[j+1]);
				swap(i+1,j+1);
			}
			else {
				//System.out.println("The swap is between "+arr[i]+" and "+arr[j+1]);
				swap(i+1,j+1);
				j++;
			}
		}
		swap(left,j);
		return j;
	}
	
	public static void Quicksort(int left,int right) {
		if(left>=right)
			return;
		else {
			int partition=Partition(left,right);
			Quicksort(left,partition);
			Quicksort(partition+1,right);
		}
	}
	
	public static void main(String args[])throws IOException {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the length of the Array");
		int len=sc.nextInt();
		arr=new int[len];
		System.out.println("Enter the "+len+" elements");
		for(int i=0;i<len;i++) {
			arr[i]=sc.nextInt();
		}
		Quicksort(0,len-1);
		for(int i=0;i<len;i++) {
			System.out.print(arr[i]+"  ");
		}
		
		
	}
	
}
