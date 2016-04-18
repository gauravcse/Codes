package graphics;

public class Student {
	
	private String name;
	private int roll;
	private String course;
	private String admission;
	private int marks[]; 

	public Student(String name,int roll,String course, String admission,int mark[]) {
		this.name = name;
		this.roll = roll;
		this.course = course;
		this.admission = admission;
		marks = new int[5];
		for(int i=0;i<5;i++) {
			marks[i]= mark[i]; 
		}
	}
	public String getName() {
		return this.name;
	}
	String getRoll() {
		return String.valueOf(this.roll);
	}
	String getCourse() {
		return (this.course);
	}
	String admission(){
		return (this.admission);
	}
	String getMarks() {
		String marksString="";
		for (int i = 0; i < 5; i++) {
			marksString += String.valueOf(this.marks[i]) + " ";
		}
		return marksString;
	}
}
