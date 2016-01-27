public class RemoveDuplicateChar {
    public String removeDuplicateLetters(String s) {
    	int size = s.length();
    	int[] count = new int[26];
    	for(char c : s){
    		count[c-'a'] ++;
    	}
    	Stack<Character> stack = new Stack<Character> ();
    	HashSet<Character> set = new HashSet<Character>();
    	for(char c: s){
    		count[c-'a']--;
    		if(stack.isEmpty){
    			stack.put(c);
    		}
    		else{
    			if(!set.contains(c)){
    				set.add(c);
    				while(!stack.isEmpty() && c<stack.peek() && count[stack.peek()] > ){
    					set.remove(stack.peek());
    					stack.pop();
    				}
    				stack.put(c);
    			}
    		}
    	}
    	for()
    }
       
}