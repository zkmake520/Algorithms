public class Solution {
    public int calculate(String s) {
    	Stack<Integer> stack = new Stack<>();
        int len = s.length();
        int sum = 0;
        int sign = 1;
        for(int i = 0; i < len; i++){
        	char c = s.charAt(i);
        	if(Character.isDigit(c)){
        		sum += sign*(c-'0');
        	}
        	else{
        		if(c == '-'){
        			sign = -1;
        		}
        		if(c == '+'){
        			sign = 1;
        		}
        		if(c == '('){
        			stack.push(sum);
        			stack.push(sign);
        			sign = 1;
        			sum = 0;
        		}
        		if(c == ')'){
        			sign = stack.pop();
        			int tmpSum = stack.pop();
        			sum = tmpSum + sign*sum;
        		}
        	}
        }
        return sum;
    }
}