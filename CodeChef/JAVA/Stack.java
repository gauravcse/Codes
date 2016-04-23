public class Stack {
    
    int maxSize;
    int top;
    int stack[];
    
    public Stack(int n) {
        maxSize = n;
        stack = new int[maxSize];
        top=-1;
    }
    
    public boolean isEmpty() {
        if(top<0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    public void push(int num) { 
        stack[++top]=num;
    }
    
    public int pop() {
        if(isEmpty()==false) {
            int popped = stack[top];
            top--;
            return popped;
        }
        else {
            System.out.println("Stack Overflow!");
            return -1;
        }
    }
}
