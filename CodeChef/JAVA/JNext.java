import java.util.Scanner;
import java.io.*;

class JNext {
    public static void main(String args[]) {
    Stack s = new Stack(5);
    System.out.println(s.isEmpty());
    s.push(5);
    System.out.println(s.isEmpty());
    s.push(4);
    s.push(3);
    System.out.println(s.pop());
    }
}