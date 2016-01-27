public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
    // using deque
    LinkedList<Integer> list = new LinkedList<Integer> ();
    for(int i = 0; i < k;i++){
    	if(list.isEmpty()){
    		list.add(nums[i]);
    	}
    	else{
    		int last = list.peekLast();
    		while(last < num[i]){
    			list.pollLast();
    			if(list.isEmpty){
    				break;
    			}
    			last = list.peekLast();
    		}
    		list.add(nums[i]);
    	}
    } 
    int [] res = new int[num.length-k+1];
    int count = 0;
    for(int i = k; i < nums.length; i++){
    	int first = list.pollFirst();
    	res[count++] = first;
    	int last = list.peekLast();
    	while(last<nums[i]){
    		list.pollLast();
    		if(list.isEmpty()){
    			break;
    		}
    		last = list.peekLast();
    	}
    	list.add(nums[i]);
    }
   	res[count] = list.pollFirst();
    return res;
}