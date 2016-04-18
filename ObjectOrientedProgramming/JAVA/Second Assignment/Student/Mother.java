package graphics;


import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class Mother implements ActionListener {
	
	JButton button1,button2;
	
	public Mother() {
		JFrame jFrame = new JFrame();
		jFrame.setSize(200,200);
		jFrame.setLocation(100, 100);
		jFrame.setTitle("HOME SCREEN");
		jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jFrame.setVisible(true);
		jFrame.setLayout(new FlowLayout());
		
		button1 = new JButton();
		button2 = new JButton();
		button1.setText("ENTER STUDENT");
		button2.setText("GET STUDENT DETAILS");
		button1.addActionListener(this);
		button2.addActionListener(this);
		jFrame.add(button1);
		jFrame.add(button2);
	}
	

	public static void main(String[] args) {
		Mother mother = new Mother();
	}


	@Override
	public void actionPerformed(ActionEvent e) {
		Object controlObject = e.getSource();
		if(controlObject == this.button1) {
			//stem.out.print("CLICKED");
			Graphical graphical = new Graphical();
		}
		else if(controlObject == this.button2) {
			Query query = new Query();
		}
		
	}

}
