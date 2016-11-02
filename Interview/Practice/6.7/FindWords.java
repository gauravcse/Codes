import java.io.*;
import java.util.*;

public class Main {

	private HashMap<String,Boolean> dict;

	Main() {
		dict = new HashMap<String,Boolean>();
		dict.put("i",new Boolean(true));
		dict.put("like",new Boolean(true));
		dict.put("gaurav",new Boolean(true));
	}

	public void checkWords(String s) {
		int l = s.length();
		String temp = "";
		for (int i = 0; i < l; i++) { 
			temp += s.charAt(i);
			if(this.dict.containsKey(temp) == true) {
				System.out.println(temp);
				temp = "";
			}
		}
	}
	
	public static void main(String[] args) {
			Main obj  = new Main();
			String s = "likegaurav";
			obj.checkWords(s);
	}

}