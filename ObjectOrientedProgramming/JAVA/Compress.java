import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;
import java.util.zip.GZIPOutputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;



public class Compress {
	
	private static void gzipFile() {
		System.out.print("ENTER THE PATH OF THE FILE : ");
		String pathString="";
		byte buffer[]=new byte[1024];
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			pathString=br.readLine();
			File file=new File(pathString);
			FileInputStream fileInputStream=new FileInputStream(file);
			System.out.print("ENTER THE NAME OF THE FILE AFTER COMPRESSION: ");
			String outpath=br.readLine();
			File file1=new File(outpath);
			FileOutputStream fileOutputStream=new FileOutputStream(file1);
			GZIPOutputStream gzip = new GZIPOutputStream(fileOutputStream);
			int readbytes;
			while((readbytes=fileInputStream.read(buffer))>0) {
				gzip.write(buffer, 0, readbytes);
			}
			fileInputStream.close();
			gzip.finish();
			gzip.close();
		}
		catch(FileNotFoundException exception) {
			System.out.println(exception.toString());
		}
		catch (IOException e) {
			System.out.println(e.toString());
		}
		finally {

		}
	}
	
	private static void zipDirectory() {
		try {
			System.out.print("ENTER THE PATH OF THE DIRECTORY : ");
			String pathString="";
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			pathString=br.readLine();
			File file=new File(pathString);
			File files[]=file.listFiles();
			Vector<String> paths = new Vector<String>();  
			for(File name : files) {
				if(name.isFile()) {
					paths.add(name.getAbsolutePath());
				}
			}
			
			int length=paths.size();
			System.out.print("ENTER THE NAME OF THE OUTPUT ZIP FILE");
			String output=br.readLine();
			FileOutputStream fileOutputStream=new FileOutputStream(output);
			ZipOutputStream zipOutputStream=new ZipOutputStream(fileOutputStream);
			for (int i = 0; i < length; i++) {
				System.out.println(paths.get(i));
				File file2=new File(paths.get(i));
				FileInputStream fileInputStream=new FileInputStream(file2);
				zipOutputStream.putNextEntry(new ZipEntry(paths.get(i)));
				byte buffer[]=new byte[1024];
				int readbytes;
				while((readbytes=fileInputStream.read(buffer))>0) {
					zipOutputStream.write(buffer, 0, readbytes);
				}
				zipOutputStream.closeEntry();
				fileInputStream.close();
			}
			zipOutputStream.finish();
			zipOutputStream.close();
			
		}
		catch(Exception exception) {
			System.out.print(exception.toString());
		}
		
	}

	public static void main(String[] args) {
		try {
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("CHOOSE \n\t1 : FOR COMPRESSING A FILE \n\t2 : FOR COMPRESSING ALL FILES IN A DIRECTORY");
			int key=Integer.parseInt(br.readLine());
			switch (key) {
			case 1:
				gzipFile();
				break;
			case 2 :
				zipDirectory();
				break;
			default:
				break;
			}
			br.close();
		}
		catch(IOException exception) {
			System.out.println(exception.toString());
		}
	}

}
