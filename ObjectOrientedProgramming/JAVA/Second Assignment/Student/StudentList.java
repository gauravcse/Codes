package graphics;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class StudentList {
	private static String FileName = "studentlist.txt";
	
	public StudentList() {
		
	}
	
	public StudentList(Student s) throws FileNotFoundException,IOException {
		/*RandomAccessFile accessFile = new RandomAccessFile(FileName, "rw");
		accessFileseek(accessFile.length());*/
		FileWriter fileWriter = new FileWriter(new File(FileName),true);
		String lineString = s.getRoll() + " " + s.getName() + " " + s.getCourse() +" "+ s.admission() +" "+ s.getMarks()+"\n";
		fileWriter.write(lineString);
		fileWriter.close();
	}
	
	public static  boolean checkUniqueRoll(int roll)throws IOException {
		String line = "";
		int rolls[] = new int[100]; 
		int count = 0;
		FileInputStream fileInputStream = new FileInputStream(new File(FileName));
		BufferedReader br = new BufferedReader(new InputStreamReader(fileInputStream));
		while((line = br.readLine()) != null) {
			StringTokenizer str = new StringTokenizer(line);
			String rollno = str.nextToken();
			try {
				if(rollno != null) {
					rolls[count++] = Integer.parseInt(rollno);
				}
			}
			catch(NumberFormatException exception) {
				exception.printStackTrace();
			}
		}
		fileInputStream.close();
		br.close();
		for(int i=0;i<count;i++) {
			if(rolls[i] == roll)
				return false;
		}
		return true;
	}
	
	public String studentData(int roll) throws NumberFormatException, IOException {
		String line= "";
		FileInputStream fileInputStream = new FileInputStream(new File(FileName));
		BufferedReader br = new BufferedReader(new InputStreamReader(fileInputStream));
		while((line = br.readLine()) != null) {
			StringTokenizer str = new StringTokenizer(line);
			String rollno = str.nextToken();
			if(Integer.parseInt(rollno) == roll) {
				br.close();
				return line;
			}
		}
		br.close();
		fileInputStream.close();
		return "Not Found";
	}
}
