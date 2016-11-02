
public class Tree {
	Node root;
	
	public Tree() {
		root = null;
	}
	
	public Tree(int data) {
		this.root = new Node(data);
	}
	
	public void insert(int data) {
		Node node = new Node(data);
		BstInsert(root,node);
		setHeight(root);
		
	}
	
	private void BstInsert(Node top,Node ptr) {
		if(top == null)
			top = ptr;
		else {
			if(ptr.data > top.data) 
				BstInsert(top.right,ptr);
			else if (ptr.data < top.data) {
				BstInsert(top.left,ptr);
			}
		}
	}
	
	private int setHeight(Node ptr) {
		if(ptr == null) {
			return 0;
		}
		else {
			ptr.leftheight = setHeight(ptr.left) + 1;
			ptr.rightheight = setHeight(ptr.right) + 1;
		}
	}
}
