import java.io.*;
import java.util.Scanner;
import java.lang.Math;
class Dance_In_Pairs {
    public static void main(String args[])throws IOException {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long k=sc.nextLong();
        long boys[]=new long[n];
        long girls[]=new long[n];
        for(int i=0;i<n;i++) {
            boys[i]=sc.nextLong();
        }
        for(int i=0;i<n;i++) {
            girls[i]=sc.nextLong();
        }
        boys=insertionSort(boys);
        girls=insertionSort(girls);
        long pair=0;
        for(int i=0;i<n;i++) {
            int num=0;
            do{
                if((girls[num]==-1)||(Math.abs(boys[i]-girls[num])>k) ){
                    num++;
                }
                else{
                    pair++;
                //    System.out.println(boys[num]+" "+girls[num]);
                    girls[num]=-1;
                    break;
                } 
            }while(num<n);
        }
        System.out.println(pair);
    }
    public static long[] insertionSort(long array[]) {
        int n = array.length;
        for (int j = 1; j < n; j++) {
            long key = array[j];
            int i = j-1;
            while ( (i > -1) && ( array [i] > key ) ) {
                array [i+1] = array [i];
                i--;
            }
            array[i+1] = key;
        }  
        return array;
    }
}