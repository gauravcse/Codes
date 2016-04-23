import java.io.*;
import java.util.Scanner;
import java.lang.*;

public class Nikhil {
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t>=1) {
            t--;
            int n=sc.nextInt();
            sc.nextLine();
            NStack stack = new NStack(n);
            while(n>=1) {
                n--;
                String command=sc.nextLine();
                char ch=command.charAt(0);
                if(ch=='p') {
                    String output="";
                    while(!stack.isEmpty()) {
                        output=stack.pop()+output;
                    }
                    System.out.println(output);
                }
                else {
                    char chr=command.charAt(3);
                    if(chr=='.') {
                        System.out.println(stack.pop());
                    }
                    else if(chr=='/') {
                        while(!stack.isEmpty()) {
                            stack.pop();
                        }
                        int len=command.length();
                        String temp="";
                        for(int i=4;i<len;i++) {
                            char c=command.charAt(i);
                            if(c!='/') {
                                temp+=c;
                            }
                            else {
                                temp="/"+temp;
                                stack.push(temp);
                                temp="";
                            }
                            if(i==(len-1)) {
                                temp="/"+temp+"/";
                                stack.push(temp);
                                temp="";
                            }
                        }
                    }
                    else {
                        int len=command.length();
                        String temp=command.substring(3,len);
                        temp=temp+"/";
                        stack.push(temp);
                    }
                }
            }
        }
    }
}
                        
                                
                                