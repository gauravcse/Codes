import java.util.Scanner;
class Insertion {
public static void main(String args[]) {
    Scanner sc=new Scanner(System.in);
    int len=sc.nextInt();
    int A[]=new int[len];
    for(int i=0;i<len;i++) {
        A[i]=(int)(Math.random()*1000);
    }
    for(int i=0;i<len;i++) {
        System.out.print(A[i]+" ");
    }
     System.out.println();
    int key,j;
    for(int i=1;i<len;i++) {
        key=A[i];
        j=i-1;
        while((j>-1)&&(A[j]>key)) {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=key;
    }
    System.out.println("Array after Sorting");
    for(int i=0;i<len;i++) {
        System.out.print(A[i]+" ");
    }
}
 
   }