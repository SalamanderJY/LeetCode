class MyQueue {
    
    private Stack<Integer> input = new Stack();
    private Stack<Integer> output = new Stack();

    /** Initialize your data structure here. */
    public MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        while (!output.empty()) {
			input.push(output.pop());
		}
		input.push(x);
		while (!input.empty()) {
			output.push(input.pop());
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return output.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        return output.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return input.empty() && output.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */