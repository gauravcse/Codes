package gaurav.hashing;

public class Link {
	
	public Node firstlink;
	
	Link() {
		firstlink = null;
	}
	public void insert(long data) {
		Node newlink= new Node(data);
		newlink.next=firstlink;
		firstlink=firstlink.next;
	}
	
	public void delete(long data) {
		Node link=firstlink;
		Node previous=null;
		while(link.next!=null) {
			if(link.ip_adress==data) {
				if(previous==null) {
					link=link.next;
					break;
				}   
				else {
					previous.next=link.next;
					break;
				}
			}
			previous=link;
			link=link.next;
		}
	}
	
	

}
