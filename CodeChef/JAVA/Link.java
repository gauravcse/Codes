public class Link {
    
    public  Node firstlink;
    
    Link() {
        firstlink=null;
    }
    
    public boolean isEmpty() {
        return (firstlink==null);
    }
    
    public void push(char ch) {
        Node insert = new Node(ch);
        insert.next=firstlink;
        firstlink=insert;
    }
    
    public char pop() {
        Node element=firstlink;
        if(!isEmpty()) {
            firstlink=firstlink.next;
            return element.data;
        }
        else {
           // System.out.println("Linked List Empty");
            return ' ';
        }
    }
    
    public char top() {
        if(!isEmpty()) {
            return firstlink.data;
        }
        else {
   //         System.out.println("Linked List Empty");
            return ' ';
        }
    }
}
    
    