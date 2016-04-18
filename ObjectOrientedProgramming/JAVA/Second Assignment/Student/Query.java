package graphics;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class Query implements ActionListener {
	
	private JTextField textField ;
	private JFrame frame;
	
	public Query() {
		frame = new JFrame();
		frame.setTitle("STUDENT DETAILS");
		frame.setSize(400,400);
		frame.setLocation(100, 100);
		frame.setVisible(true);
		FlowLayout flowLayout = new FlowLayout();
		frame.setLayout(flowLayout);
		
		JLabel jlabel = new JLabel("STUDENT ROLL NUMBER : ");
		frame.add(jlabel);
		textField = new JTextField(80);
		frame.add(textField);
		JButton button = new JButton();
		button.setText("ENTER");
		frame.add(button);
		button.addActionListener(this);
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			StudentList studentList= new StudentList();
			int roll = Integer.parseInt(textField.getText());
			String data=studentList.studentData(roll);
			if(!data.equals("Not Found")) {
				String array[] = data.split(" ");
				String out = "Name : "+array[1]+"\n"+"Roll No : "+array[0]+"\n"+"Course : "+array[2]+"\n";
				//System.out.print(out);
				String cgpa = String.valueOf((Integer.parseInt(array[4])+Integer.parseInt(array[5])+Integer.parseInt(array[6])+Integer.parseInt(array[7])+Integer.parseInt(array[8]))/50.0);
				out+="CGPA : "+cgpa;
				JOptionPane.showMessageDialog(null, out);
			}
			else {
				JOptionPane.showMessageDialog(null, data);
			}
		}
		catch(Exception exception) {
			exception.printStackTrace();
		}
		
	}

	

}
