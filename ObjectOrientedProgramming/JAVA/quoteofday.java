import java.util.Date;
import java.util.Calendar;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Random;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.RandomAccessFile;

class quoteofday{

public static final String morningquote[]={

 "Be yourself; everyone else is already taken.― Oscar Wilde",
            "A room without books is like a body without a soul. ― Marcus Tullius Cicero",
            "Be the change that you wish to see in the world. ― Mahatma Gandhi",
            "If you tell the truth, you don't have to remember anything. ― Mark Twain",
            "If you want to know what a man's like, take a good look at how he treats his inferiors, not his equals.― J.K. Rowling",
            "To live is the rarest thing in the world. Most people exist, that is all.― Oscar Wilde",

};
public static final String eveningquote[]={
 "Without music, life would be a mistake. ― Friedrich Nietzsche",
            "Always forgive your enemies, nothing annoys them so much. ― Oscar Wilde",
            "Life isn't about getting and having, it's about giving and being. –Kevin Kruse",
            "Whatever the mind of man can conceive and believe, it can achieve. –Napoleon Hill",
            "Strive not to be a success, but rather to be of value. –Albert Einstein",                  

};
public static final String nightquote[]={
"Be pleasant until ten o’clock in the morning and the rest of the day will take care of itself. — Elbert Hubbard",
	     "Morning is an important time of day, because how you spend your morning can often tell you what kind of day you are going to have. — Lemony Snicket",
	     "An early-morning walk is a blessing for the whole day. — Henry David Thoreau",
 "Prayer is the key of the morning and the bolt of the evening. Mahatma Gandhi",
	     "The man who says his evening prayer is a captain posting his sentinels. He can sleep. Charles Baudelaire",
	     "There are worse things in life than death. Have you ever spent an evening with an insurance salesman? Woody Allen"
};






private int flag=0;
public String get(){

String x=new SimpleDateFormat("yyyyMMdd_HHmmss").format(Calendar.getInstance().getTime());

return x;
}

public String time(){
quoteofday q= new quoteofday();
String t= q.get();
String y=t.substring(9,11);
return y;
}
public String handle_file(int k,File file) throws IOException{
		String str;
		Scanner scanner=new Scanner(file);    
        	Random rand = new Random();
		if(k==1)
			 str= this.morningquote[rand.nextInt(this.morningquote.length)];
		else if(k==2)
			 str= this.eveningquote[rand.nextInt(this.eveningquote.length)];
		else
			str= this.nightquote[rand.nextInt(this.nightquote.length)];
		while(scanner.hasNextLine()){
     			if(str.equals(scanner.nextLine())){
        		this.flag=1;
        		break;
      			}
				
		}
		return(str);
	}
	public void add_file(int k,File file) throws IOException{
		 BufferedReader bfr;

		 String h=handle_file(k,file);
		 if(this.flag==0){
			System.out.println(">>>>>>"+h);
			try{
           			bfr=new BufferedReader(new FileReader(file));

           			 FileWriter fw=new FileWriter(file,true);            
          			 fw.append(h+"\n");
          		         bfr.close();
           			 fw.close();

       			 }catch(FileNotFoundException fex){
            			fex.printStackTrace();
        		}
		}
		else{
			
			System.out.println("FREQUENT CODE : "+h);
		}
							

    	}

public static void main(String[] args) throws IOException{
quoteofday q= new quoteofday();
 Scanner S = new Scanner(System.in);
	       System.out.println("generating random quotes");
	       System.out.println();
	       System.out.print("type javaQuoteOfTheDay to print new quote");
	       File file=new File("history.txt");       
               if(!file.exists()){
            		file.createNewFile();
        	}
		while(true){
			q.flag=0;
        		System.out.println();
			String ch = S.nextLine();
			if(ch.equals("quit"))
				break;
			else{ 
					System.out.println("\t\t the time of day is: "+q.get());
					String g=q.time();
					if(Integer.parseInt(g)<12){
						System.out.println("MORNING QUOTES");
						q.add_file(1,file);
					}
					else if(Integer.parseInt(g)<18 && Integer.parseInt(g)>=12){
						System.out.println("EVENING QUOTES");
						q.add_file(2,file);
					}
					else if(Integer.parseInt(g)<=24 && Integer.parseInt(g)>=18){
						System.out.println("NIGHT QUOTES");
						q.add_file(3,file);
					}
				}
			}
		}
	
}

