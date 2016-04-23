
public class Test {
	public static void main(String args[]) throws InterruptedException {
		RandomNumber rn1 = new RandomNumber(1000,1500,"matrix1.txt");
		RandomNumber rn2 = new RandomNumber(25000,25000,"matrix2.txt",1,20000);
		
		Thread t1 = new Thread(rn1);
		Thread t2 = new Thread(rn2);
		t1.setName("Small");
		t2.setName("Large");
		t1.start();
		t2.start();
		for(int i = 1 ; i < 100 ; i++) {
			if(t1.isAlive()) {
				System.out.println("First THREAD ALIVE");
			}
			else {
				System.out.println("First THREAD DEAD");
			}
			if(t2.isAlive()) {
				System.out.println("Second THREAD ALIVE");
			}
			Thread.sleep(1000);
		}
	}
}
