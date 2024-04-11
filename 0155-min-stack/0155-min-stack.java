class MinStack {

    Stack<Integer> st = new Stack<Integer>();
    Stack<Integer> Min_val = new Stack<Integer>();
    
    public void push(int val) {
        if(Min_val.isEmpty() || val <= Min_val.peek()){
            Min_val.push(val);
        }
        st.push(val);
    }
    
    public void pop() {
        if(Min_val.peek().equals(st.peek())){
            Min_val.pop();
        }
        st.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return Min_val.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */