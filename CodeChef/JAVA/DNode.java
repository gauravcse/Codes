public class DNode {
    static int items=0;
    public int data;
    DNode next;
    DNode previous;
    DNode(int data) {
        this.data=data;
        items++;        
    }
    
    public void display() {
        System.out.println(data);
    }
}
