public class Stacks {
    final int defaultSize = 1024;
    int maxSize;
    public int top;
    int stack[];
    
    public Stacks() {
        top=-1;
        stack = new int[defaultSize];
        maxSize = defaultSize;
    }
    
    public Stacks(int num) {
        top=-1;
        maxSize = num;
        stack = new int[maxSize];
    }
    
    public boolean isEmpty() {
        if(top < 0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    public void push(int value) {
        if(top == maxSize) {
           // System.out.println("Stack Overflow! Cannot Push Element");
        }
        else {
            stack[++top]=value;
        }
    }
    
    public int pop() {
        if(top < 0) {
           // System.out.println("Stack Underflow! No Element to be Popped");
            return 'f' ; 
        }
        else {
            int value = stack[top];
            stack[top--]='f';
            return value;
        }
    }
    
    public int peek() {
        if(top < 0) {
            //System.out.println("Stack Empty");
            return -1;
        }
        else {
            return stack[top];
        }
    }
}
            