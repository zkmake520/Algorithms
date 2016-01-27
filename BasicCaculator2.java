public class Solution {
    public int calculate(String s) {
        int len = s.length();
        int sign = 1;
        int sum = 0;
        LinkedList<Integer>  stack = new LinkedList<>();
        for(int i =0; i <len; i++){
        	char c = s.charAt(i);
        	if(Character.isDigit(c)){
        	    int num = 0;
        	    num = c-'0';
        	    i++;
        	    while(i< len && Character.isDigit(s.charAt(i))){
        	        num = num*10+ s.charAt(i)-'0';
        	        i++;
        	    }
        	    if(sign == 1 || sign == -1){
        	    	sum = num;
        	    }
        	    else{
        	    	if(sign == 2){
        	    		sum *= num; 
        	    	}
        	    	else{
        	    		sum = sum/num;
        	    	}
        	    }
        	    if(i == len){
        	    	stack.add(sum);
        	        break;
        	    }else{
        	        i--;
        	    }
        	}
        	if(c == '*'){
        		sign = 2;
        	}
        	if(c == '/'){
        		sign = -2;
        	}
        	if(c == '+'){
        		sign = 1;
        		stack.add(sum);
        		stack.add(sign);
        		sum = 0;
        	}
        	if(c == '-'){
        		sign = -1;
        		stack.add(sum);
        		stack.add(sign);
        		sum = 0;
        	}
        }
        sum = 0 ;
        sign = 1;
        int i = 0;
        while(!stack.isEmpty()){
        	if( i % 2 == 0){
        		sum += sign* stack.poll();
        	}
        	else{
        		sign = stack.poll();
        	}
        	i++;
		}
		return sum;

    }
}