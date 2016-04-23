import java.util.Scanner;

public class Permutation {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t>0) {
			t--;
			String permute="";
			Stack stack=new Stack();
			String word=sc.next();
			int len=word.length();
			int count=len-1;
			stack.push(word.charAt(count));
			while(count>0 && word.charAt(count-1)>=word.charAt(count)) {
				stack.push(word.charAt(count-1));
				count--;
			}
			if(count==0) {
				System.out.println("no answer");
			}
			else {
				String sub="";
				if((count-1)!=0) {
					sub=word.substring(0,count-1);
					//System.out.println("Entered");
				}
				char ch=word.charAt(count-1);
				String imp=String.valueOf(ch);
				String last=String.valueOf(stack.pop());
				permute=last+imp;
				//System.out.println(permute);
				String rest="";
				boolean flag=true;
				while(!stack.isEmpty()) {
					char k=stack.pop();
					if(k>=ch){
						rest=String.valueOf(k)+rest;
					}
					else {
						rest+=String.valueOf(k);
					}
				}
				permute=sub+rest+permute;
				System.out.println(permute);
			}
		}
	}
}
