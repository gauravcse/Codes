import java.io.*;
import java.util.Scanner;

public class Postfix {
    
    public static void main(String args[]) {
        
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        System.out.println();
        char arr[]=s.toCharArray();
        int len=arr.length;
        
        Link stack = new Link();
        for(int i=0;i<len;i++) {
            char ch=arr[i];
            if(ch>='0' && ch<='9') {
                System.out.print(ch);
            }
            else if(ch=='(') {
                stack.push(ch);
            }
            else if(ch==')') {
                while(stack.top()!='(') {
                    System.out.print(stack.pop());
                }
                stack.pop();
            }
            else if(ch=='/') {
                if(stack.top()=='(' || stack.isEmpty()) {
                    stack.push(ch);
                    continue;
                }
                while(stack.top()!='(' && !stack.isEmpty()) {
                    System.out.print(stack.pop());
                }
                stack.push(ch);
            }
            else if(ch=='*') {
                if(stack.top()=='(' || stack.isEmpty()||stack.top()=='/') {
                    stack.push(ch);
                    continue;
                }
                while(stack.top()!='(' && !stack.isEmpty()){
                    char t=stack.top();
                    if(t!='/') {
                        System.out.print(stack.pop());
                    }
                }
                stack.push(ch);
            }
            else if(ch=='+') {
                if(stack.top()=='(' || stack.isEmpty() || stack.top()=='/' || stack.top()=='*') {
                    stack.push(ch);
                    continue;
                }
                while(stack.top()!='(' && !stack.isEmpty()){
                    char t=stack.top();
                    if(t=='-') {
                        System.out.print(stack.pop());
                    }
                }
                stack.push(ch);
            }
            else if(ch=='-') {
                    stack.push(ch);
                    continue;
            }
        }
        while(!stack.isEmpty()) {
                System.out.print(stack.pop());
        }
    }
}