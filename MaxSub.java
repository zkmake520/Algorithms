public class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
    	int rst = 0;
    	HashMap<Integer, Integer> map = new HashMap<>();
    	int sum = 0;
    	for(int i = 0; i < nums.length; i++){
    		sum += nums[i];
    		if(!map.containsKey(sum)){
    			map.put(sum,i);
    		}
    		if(map.containsKey(sum-k)){
    			rst = i-map.get(sum-k)+1;
    		}

    	}
    	return rst;
    }
}