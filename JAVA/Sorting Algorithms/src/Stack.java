public class Stack {
	int maxSize;
	int top;
	char stack[];

	Stack() {
		maxSize=100;
		stack=new char[maxSize];
		top=-1;
	}
	
	boolean isEmpty() {
		if(top<0)
			return true;
		else
			return false;
	}
	
	void push(char ch) {
		if(top<maxSize) {
			top++;
			stack[top]=ch;
		}
		else {
			return ;
		}
	}
	
	char pop() {
		if(!isEmpty()) {
			return stack[top--];
		}
		else
			return '\0';
	}
}

