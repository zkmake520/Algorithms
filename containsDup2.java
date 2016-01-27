public class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer,Integer> set = new HashSet<>();
        for(int i = 0; i < nums.length; i++){
        	int num = nums[i];
        	if(set.containsKey(num) && Math.abs(set.get(num)-i) <= k){
        		return true;
        	}
        	else {
        		set.put(num,i);
        	}
        }
        return false;
    }
}