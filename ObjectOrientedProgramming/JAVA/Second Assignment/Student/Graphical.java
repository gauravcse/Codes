package graphics;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class Graphical implements ActionListener {
	JButton button;
	private JTextField field,field1,field2,field3,field4,field5,field6,field7;
	Student student;
	StudentList studentList;
	
	public Graphical() {
		JFrame frame = new JFrame();
		frame.setTitle("Student Info");
		frame.setSize(400,400);
		frame.setLocation(100, 100);
		frame.setVisible(true);
		FlowLayout flowLayout = new FlowLayout();
		frame.setLayout(flowLayout);
		
		JLabel myLabel = new JLabel("STUDENT NAME : ");
		frame.add(myLabel);
		field = new JTextField(110);
		frame.add(field);
		JLabel myLabel1 = new JLabel("STUDENT ROLL NUMBER : ");
		frame.add(myLabel1);
		field1 = new JTextField(106);
		frame.add(field1);
		JLabel myLabel2 = new JLabel("STUDENT COURSE : ");
		frame.add(myLabel2);
		field2 = new JTextField(109);
		frame.add(field2);
		
		JTextArea marksArea = new JTextArea("MARKS IN FIVE SUBJECTS", 2, 5);
		marksArea.setBackground(Color.green);
		frame.add(marksArea);
		JLabel myLabel3 = new JLabel("SUBJECT 1 : ");
		frame.add(myLabel3);
		field3 = new JTextField(10);
		frame.add(field3);
		JLabel myLabel4 = new JLabel("SUBJECT 2 : ");
		frame.add(myLabel4);
		field4 = new JTextField(10);
		frame.add(field4);
		JLabel myLabel5 = new JLabel("SUBJECT  3: ");
		frame.add(myLabel5);
		field5 = new JTextField(10);
		frame.add(field5);
		JLabel myLabel6 = new JLabel("SUBJECT 4 : ");
		frame.add(myLabel6);
		field6 = new JTextField(10);
		frame.add(field6);
		JLabel myLabel7 = new JLabel("SUBJECT 5 : ");
		frame.add(myLabel7);
		field7 = new JTextField(10);
		frame.add(field7);
		
		button = new JButton();
		button.setText("SUBMIT");
		button.addActionListener(this);
		frame.add(button);
	}
	
	/*public static void main(String[] args) {
		Graphical graphical = new Graphical();
		
	}*/

	@Override
	public void actionPerformed(ActionEvent e) {
		String name = field.getText();
		int roll=-1;
		try {
			roll = Integer.parseInt(field1.getText());
		}
		catch (NumberFormatException e1){
			e1.printStackTrace();
		}
		String course = field2.getText();
		String admission = "";
		int mark[] = new int[5];
		try {
			mark[0]=Integer.parseInt(field3.getText());
			mark[1]=Integer.parseInt(field4.getText());
			mark[2]=Integer.parseInt(field5.getText());
			mark[3]=Integer.parseInt(field6.getText());
			mark[4]=Integer.parseInt(field7.getText());
		}
		catch (NumberFormatException e1){
			e1.printStackTrace();
		}
		student = new Student(name, roll, course, admission, mark);
		try {
			if( StudentList.checkUniqueRoll(roll) )  {
				studentList = new StudentList(student);
				JOptionPane.showMessageDialog(null, "DATABASE UPDATED");
			}
			else {
				JOptionPane.showMessageDialog(null, "ENTER A UNIQUE ROLL NUMBER");
			}
		} catch (IOException e1) {
			e1.printStackTrace();
		}
	}

}
