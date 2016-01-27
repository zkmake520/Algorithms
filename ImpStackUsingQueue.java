class MyStack {
    // Push element x onto stack.
    Queue< Integer> queue = new LinkedList<>();

    public void push(int x) {
        queue.add(x); 
    }

    // Removes the element on top of the stack.
    public void pop() {
       int size = queue.size();
       queue.remove(size-1); 
    }

    // Get the top element.
    public int top() {
       queue.get(queue.size()-1); 
    }

    // Return whether the stack is empty.
    public boolean empty() {
       return queue.isEmpty(); 
    }
}