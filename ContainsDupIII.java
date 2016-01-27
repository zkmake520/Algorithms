public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
    	HashMap<Integer,ArrayList<Integer>> map= new HashMap<>();
    	// use treeset , the basic idea is that we only need to consider the k elements,
    	//if we push the element into set follow the original order
    	if( k <1 || t < 0){
    		return false;
    	}
    	TreeSet<Integer> set = new TreeSet<Integer>();
        for(int i = 0; i < nums.length; i ++){
        	int num = nums[i];
        	if(( set.floor(num) != null && num <= set.floor(num) +t) ||
        		(set.ceiling(num) != null && num + t>= set.ceiling(num))){
        		return true;
        	}
        	else{
        		set.add(num);
        	}
        	if(i >= k){
        		set.remove(nums[i-k]);
        	}
        }
        return false;
    }
}