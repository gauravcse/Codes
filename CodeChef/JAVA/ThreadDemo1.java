public class ThreadDemo1 implements Runnable
{
    Thread t;
    public ThreadDemo1() {
        t = new Thread(this,"MyThread");
        t.start();
        
    }
    public void run() {
        try {
            for(int i=-1;i>=-10;i--) {
                System.out.println(i);
                Thread.sleep(1000);
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
}
