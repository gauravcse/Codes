import java.io.*;
import java.util.*;

public class Parenthesis {
	public boolean checkStack(String input)throws NullPointerException,IllegalArgumentException,ClassCastException  {
		char array[]=input.toCharArray();
		Deque<Character> stack=new ArrayDeque<Character>();
		boolean flag=false;
		for(char ch : array) {
			if(stack.size()==0)
				stack.addFirst(ch);
			else {
				if(ch=='(' || ch=='[' || ch=='{')
					stack.addFirst(ch);
				else if(ch==')') {
					if(stack.peek()=='(')
						stack.pop();
					else  {
						flag=true;
						break;
					}
				}
				else if(ch=='}') {
					if(stack.peek()=='{')
						stack.pop();
					else  {
						flag=true;
						break;
					}
				}
				else if(ch==']') {
					if(stack.peek()=='[')
						stack.pop();
					else  {
						flag=true;
						break;
					}
				}
			}
		}
		return flag;
	}

	public static void main(String args[])throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader brout=new BuffredReader(new OutputStreamWriter(System.out));
		//Console console=System.console();
		//console.writeline("ENTER THE PARENTHESIS : ");
		while(true) {
			System.out.println("ENTER THE PARENTHESIS : ");
			String input=br.readLine();
			input=input.trim();
			Parenthesis part=new Parenthesis();
			boolean flag=part.checkStack(input);	
			if(flag)
				System.out.println("NO");
			else
				System.out.println("YES");
				//console.writeLine("YES");
			System.out.print("DO YOU WANT TO CONTINUE : ");
			if((br.readLine()).equals("NO"))
				break;
		}
	}
}
