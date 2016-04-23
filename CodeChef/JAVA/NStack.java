public class NStack {
    
    int maxSize;
    int top;
    String stack[];
    
    public NStack(int n) {
        stack = new String[n];
        top = -1;
        maxSize = n;
    }
    
    public boolean isEmpty() {
        if(top < 0) {
            return true;
        }
        else return false;
    }
    
    public void push(String element) {
        stack[++top]=element;
    }
    
    public String pop() {
        if(!isEmpty()) {
            return stack[top--];
        }
        else return null;
    }
    
    public String top() {
        if(!isEmpty()) {
            return stack[top];
        }
        else return null;
    }
}
    
    