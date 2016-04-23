public class Queue {
    
    private int que[];
    final int Maxsize=10000;
    private int rear,front,len;
    
    Queue(int n) {
        que=new int[n];
        for(int i=0;i<n;i++)
            que[i]=-9999;
        rear=front=-1;
        len=0;
    }
    
    Queue() {
        que=new int[Maxsize];
        for(int i=0;i<Maxsize;i++)
            que[i]=-9999;
        rear=front=-1;
        len=0;
    }
    
    public boolean isempty() {
        return (front==-1 && rear==-1);
    }
    
    public int length() {
        return len;
    }
    
    public void enqueue(int e) {
        if(isempty()) {
            front=rear=0;
            que[rear]=e;
            return;
        }
        que[++rear]=e;
    }
    
    public int dequeue() {
        if(isempty())
            return -9999;
        return que[front++];
    }
    
    public void printqueue() {
        if(!isempty()) {
            for(int i=front;i<=rear;i++) {
                System.out.print(que[i]+"  ");
            }
            System.out.println();
        }
    }
}
    
    
        