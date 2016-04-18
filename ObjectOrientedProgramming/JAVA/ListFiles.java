/***
 * 			CREATED BY GAURAV MITRA  
 ***/

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;


public class ListFiles {

	public static void listDirectory(String directoryName, ArrayList<File> files) {
	    File directory = new File(directoryName);

	    // get all the files from a directory
	    File[] fList = directory.listFiles();
	    for (File file : fList) {
	        if (file.isFile()) {
	            files.add(file);
	        } else if (file.isDirectory()) {
	            listDirectory(file.getAbsolutePath(), files);
	        }
	    }
	}
	
	public static void parameterCheck(String parameters[]) {
		if(parameters[1]=="-") {
			ArrayList<File> files=new ArrayList<File>();
			listDirectory(parameters[0],files);
			ListF(files);
		}
		else {
			if(parameters[1].equals("-s")) {
				ArrayList<File> files=new ArrayList<File>();
				listDirectory(parameters[0],files);
				ListFilesBySize(files);
			}
			else {
				if(parameters[1].equals("-d")) {
					ArrayList<File> files=new ArrayList<File>();
					listDirectory(parameters[0],files);
					ListFilesByDate(files);
				}
			}
		}
	}
	
	private static void ListFilesBySize(ArrayList<File> files) {
		//File arrayFile[] = new File[files.size()];
		File arrayFile[]=files.toArray(new File[files.size()]);
		Arrays.sort(arrayFile,new Comparator<File>(){
				public int compare(File file1,File file2) {
					return Long.compare(file1.length(), file2.length());
				}
		});
		for(File file:arrayFile) {
			System.out.println(file.getAbsolutePath()+"\t"+file.length());
		}
	}
	
	
	private static void ListF(ArrayList<File> files) {
		Iterator<File> iterator=files.iterator();
		while (iterator.hasNext()) {
			File file=iterator.next();
			System.out.println(file.getAbsolutePath());
		}
	}
	
	private static void ListFilesByDate(ArrayList<File> files) {
		//File arrayFile[] = new File[files.size()];
		File arrayFile[]=files.toArray(new File[files.size()]);
		Arrays.sort(arrayFile,new Comparator<File>(){
				public int compare(File file1,File file2) {
					return Long.compare(file1.lastModified(), file2.lastModified());
				}
		});
		for(File file:arrayFile) {
			System.out.println(file.getAbsolutePath()+"\t"+file.lastModified());
		}
	}
	
	public static void main(String[] args)throws IOException {
		String pathString[]=new String[2];
		Scanner sc=new Scanner(System.in);
		pathString[0]=sc.nextLine();
		pathString[1]=sc.nextLine();
		System.out.println(pathString[0]+"\t\t"+pathString[1]);
		parameterCheck(pathString);
	}

}
