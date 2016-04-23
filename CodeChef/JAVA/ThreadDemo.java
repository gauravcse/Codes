public class ThreadDemo implements Runnable
{
    Thread t;
    public ThreadDemo() {
        t = new Thread(this,"MyThread");
        t.start();
        
    }
    public void run() {
        try {
            for(int i=1;i<=10;i++) {
                System.out.println(i);
                Thread.sleep(500);
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
}
