public class DoublyLinked {
    public DNode firstlink;
    public DNode lastlink;
    
    DoublyLinked() {
        firstlink=null;
        lastlink=null;
    }
    
    public boolean isEmpty() {
        if(DNode.items==0) {
            return true;
        }
        else  {
            return false;
        }
    }
    
    public void insertBeg(int data) {
        DNode newnode = new DNode(data);
        if(isEmpty()) {
           lastlink=newnode;
           firstlink.next=newnode;
        }
        else {
            newnode.next=firstlink;
            firstlink=newnode;
        }
    }
    
    public void insertEnd(int data) {
        DNode newnode = new DNode(data);
        if(isEmpty()) {
            firstlink=newnode;
            newnode.next=lastlink;
        }
        else {
            lastlink.next=newnode;
            newnode=lastlink;
        }
    }
}

            