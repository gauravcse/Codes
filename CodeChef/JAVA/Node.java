public class Node {
    
    public char data;
    public Node next;
    
    public Node(char value) {
        this.data=value;
    }
    
    public void display() {
        System.out.print(data);
    }
}