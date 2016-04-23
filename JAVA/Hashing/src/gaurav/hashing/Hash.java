package gaurav.hashing;
import java.io.*;
import java.util.Scanner;

public class Hash {

	public static void main(String[] args){
		try {
		Scanner sc=new Scanner(System.in);
		Link link = new Link();
		System.out.print("Enter the number of records to be stored\n");
		int n=sc.nextInt();
		int prime=n-1;
		int count=n;
		while(!(prime>n)) {
		    if(primecheck(count)==true)
		    	prime=count;
		    count++;
		}
		Node hash[]=new Node[prime];
		System.out.println("Enter two space separated arbitrary Numbers\n");
		int num1=sc.nextInt();
		int num2=sc.nextInt();
		System.out.println("Enter the phone numbers sequentailly");
		for(int k=1;k<=n;k++) {
			long number=sc.nextLong();
			long nummod=(((number%1000)*num1)+((number/1000)*num2));
			hash[nummod].insert()
		}
	}

}
