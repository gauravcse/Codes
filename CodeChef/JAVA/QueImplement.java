public class QueImplement {
    
    public static void main(String args[]) {
        Queue obj=new Queue(10);
        obj.enqueue(5);
        obj.enqueue(25);
        obj.printqueue();
        obj.enqueue(16);
        obj.enqueue(12);
        obj.enqueue(19);
        obj.printqueue();
        obj.dequeue();
        obj.printqueue();
        obj.dequeue();
        obj.printqueue();
    }
}