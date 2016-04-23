package gaurav.hashing;

public class Node {
    
	public long ip_adress;
    public Node next;
    
    public Node(long ip_adress) {
    	this.ip_adress=ip_adress;
    }
    
    public void Display() {
    	System.out.print(ip_adress);
    }
    
}
