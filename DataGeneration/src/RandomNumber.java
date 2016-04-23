import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Random;


public class RandomNumber implements Runnable{
	
	private int row;
	private int column;
	private String fileName;
	private int low;
	private int high;
	
	public RandomNumber(int row,int column,String file,int low,int high) {
		this.row = row;
		this.column = column;
		this.fileName = file;
		this.low = low;
		this.high = high;
	}

	public RandomNumber(int row,int column,String file) {
		this.row = row;
		this.column = column;
		this.fileName = file;
		this.low = 0;
		this.high = 1000;
	}
	@Override
	public void run() {
		BufferedWriter bw = null;
		try {
			FileOutputStream fis = new FileOutputStream(new File(fileName));
			bw = new BufferedWriter(new OutputStreamWriter(fis));
			for(int i = 0; i < this.row; i++) {
				String output = String.valueOf(i+1) + " ";
				Random rand = new Random();
				for(int j = 0; j < this.column; j++) {
					int value = rand.nextInt(this.high - this.low)+ this.low;
					output += String.valueOf(value) + " ";
				}
				bw.write(output + "\n");
			}
		}
		catch( FileNotFoundException e ) {
			e.printStackTrace();
		}
		catch ( IOException e) {
			e.printStackTrace();
		}
		finally {
			if (bw != null) {
		        try { 
		            bw.close();
		        } catch(IOException ioe) {
		            ioe.printStackTrace();
		        }
		    }
		}
	}

}

