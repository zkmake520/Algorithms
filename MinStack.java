import java.util.*;
public  class MinStack{
	//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
	int min = Integer.MAX_VALUE;
	Stack<Long> stack = new Stack<>();
	public void push(int x) {
		if(x <= min){
			stack.push(min);
			min = x;
		} 
		stack.push(x);
    }

    public void pop() {
       	int value = stack.pop();
       	if(value == min){
       		min = stack.pop();
       	}
    }

    public int top() {
		return stack.peek();       	 
    }

    public int getMin() {
       	return min; 
    }


    //continue to optimize: even through we only need to use one stack, but we need to any old min value onto stack,
    //consider an case : 5,4,3,2,1 every element need to be pushed twice. can we do better?
    // since we use minus, pay attention to the possible overflow
    //
    public void push(int x) {
    	if(stack.isEmpty()){
    		stack.push(0L);
    		min = x;
    	}
    	else{
			stack.push(x-min);
			if(x-min < 0){ // x will be the new min value
				min = x;
			}
    	}
    }

    public void pop() {
       	long value = stack.pop();
       	if(value < 0){ 
       		min = min - value; 
       	}
    }

    public int top() {
    	long top= stack.peek();
    	if(top < 0){
			return stack.peek()+min;       	 
    	}
    	else{
    		return min;
    	}
    }
    public int getMin() {
       	return (int)min; 
    }

}