
public class Node {
	int data;
	Node left,right;
	int leftheight,rightheight;
	
	public Node(int data) {
		this.data = data;
		this.left = this.right = null;
		this.leftheight = this.rightheight = 0;
	}
}
