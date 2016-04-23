import java.io.*;
import java.util.Scanner;

public class Infix {
    
    public static void main(String args[]) {
        
        Scanner sc=new Scanner(System.in);
        int pos = sc.nextInt();
        while(pos>0) {
        pos--;
        String s=sc.next();
        System.out.println();
        char arr[]=s.toCharArray();
        int len=arr.length;
        
        Stacks stack = new Stacks(len);
        for(int i=0;i<len;i++) {
            char ch=arr[i];
            if(ch>='a' && ch<='z') {
                System.out.print(ch);
            }
            else if(ch=='(') {
                stack.push(ch);
            }
            else if(ch==')') {
                while(stack.topEle()!='(') {
                    System.out.print(stack.pop());
                }
                stack.pop();
            }
            else if(ch=='^') {
                if(stack.topEle()=='(' || stack.isEmpty()) {
                    stack.push(ch);
                    continue;
                }
                while(stack.topEle()!='(' && !stack.isEmpty()) {
                    System.out.print(stack.pop());
                }
                stack.push(ch);
            }
            else if(ch=='/') {
                if(stack.topEle()=='(' || stack.isEmpty()) {
                    stack.push(ch);
                    continue;
                }
                while(stack.topEle()!='(' && !stack.isEmpty()) {
                    char t=stack.topEle();
                    if(t!='^') {
                    System.out.print(stack.pop());
                    }
                }
                stack.push(ch);
            }
            else if(ch=='*') {
                if(stack.topEle()=='(' || stack.isEmpty()||stack.topEle()=='/') {
                    stack.push(ch);
                    continue;
                }
                while(stack.topEle()!='(' && !stack.isEmpty()){
                    char t=stack.topEle();
                    if(t!='/' || t!='^') {
                        System.out.print(stack.pop());
                    }
                }
                stack.push(ch);
            }
            else if(ch=='+') {
                if(stack.topEle()=='(' || stack.isEmpty() || stack.topEle()=='/' || stack.topEle()=='*') {
                    stack.push(ch);
                    continue;
                }
                while(stack.topEle()!='(' && !stack.isEmpty()){
                    char t=stack.topEle();
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
        while(!stack.isEmpty()&&stack.pop()!='(') {
                System.out.print(stack.pop());
        }
        System.out.println();
    }
}
}