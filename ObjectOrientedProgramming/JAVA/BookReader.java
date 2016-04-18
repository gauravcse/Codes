import java.io.*;
/*import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;*/
import java.util.*;
/*import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
*/


public class BookReader {
	
	private static HashMap<String, String> wordCount = new HashMap<String,String>();
	private	static final String output="THE PATHNAME OF THE FILE WHERE THE BOOK IS STORED : ";
	
	private static void readFile(String path)throws FileNotFoundException,IOException {
		File file=new File(path);
		FileReader fileRead=new FileReader(file);
		BufferedReader br=new BufferedReader(fileRead);
		String line="";
		int lineCount=0;
		while((line=br.readLine())!= null) {
			lineCount++;
			processLine(line,lineCount);
		}
	}
	
	private static void processLine(String line,int lineNumber) {
		StringTokenizer str = new StringTokenizer(line);
		while(str.hasMoreTokens()) {
			String word=str.nextToken();
			word=processWord(word);
			if(word!=null || word!="")
				updateHashMap(word,lineNumber);
		}
	}
	
	private static String processWord(String word) {
		word=word.trim();
		word=word.toLowerCase();
		char ch[]=word.toCharArray();
		String newWord="";
		for(char c : ch) {
			if(Character.isAlphabetic(c))
				newWord+=c;
		}
		return newWord;
	}
	
	private static void updateHashMap(String key, int value) {
		if(!wordCount.containsKey(key)) {
			wordCount.put(key, String.valueOf(value));
		}
		else {
			String oldKey=wordCount.get(key);
			String newKey=oldKey+" "+String.valueOf(value);
			wordCount.put(key, newKey);
		}
	}
	
	private static void writeWordCount()throws IOException {
		/*ArrayList<String> keys = new ArrayList<String>(wordCount.keySet());
		Collections.sort(keys);*/
		Map<String, String> treeMap= new TreeMap<String,String>(wordCount);
		writeMap(treeMap);
	}
	
	private static void writeMap(Map<String,String> map)throws IOException {
		File outFile = new File("output.txt");
		FileWriter fileWriter=new FileWriter(outFile);
		BufferedWriter bw=new BufferedWriter(fileWriter);
		Set<Map.Entry<String, String>> set=map.entrySet();
		Iterator<Map.Entry<String, String>> iterator=set.iterator();
		while(iterator.hasNext()) {
			Map.Entry<String,String> entry=(Map.Entry)iterator.next();
			String key = (String) entry.getKey();
			String value = (String) entry.getValue();
			bw.write(key+"\t"+value+"\n");
		}
		bw.close();
	}
	
	public static void main(String[] args)throws IOException {
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		System.out.println(output);
		String pathName=new String(br.readLine());
		readFile(pathName);
		writeWordCount();
		br.close();
	}

}
