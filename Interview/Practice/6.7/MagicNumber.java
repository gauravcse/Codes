import java.io.*;
import java.util.Scanner;

public class Main {
	private long dp[];
	private int n;

	Main(int n) {
		this.n = n;
		dp = new long[n+1];
	}

	public long buildNumber() {
		dp[1] = 5;
		dp[2] = 25;
		dp[3] = 30;
		int power = 3,count = 3;
		do {
			dp[++count] = (long)Math.pow(5,power);
			power ++;
			int concount = count;
			for(int i = 0; i <= concount - 1 && count < n; i++) {
				dp[count + 1] = dp[concount] + dp[i + 1];
				count += 1;
			}
		} while(count < n);
		return dp[n];
	}

	public static void main(String[] args) {
			Main obj  = new Main(125);
			System.out.println(obj.buildNumber());
	}

}