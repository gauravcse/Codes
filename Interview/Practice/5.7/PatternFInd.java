import java.util.*;
import java.util.regex.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    String hello = "100001abc1011001";
        Pattern pattern = Pattern.compile("1[0]+1");
        Matcher  matcher = pattern.matcher(hello);
        int count = 0;
        while (matcher.find())
            count++;

        System.out.println(count);   
    }
}
