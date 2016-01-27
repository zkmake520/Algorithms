public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
    	int sum = 0;
    	int min = 0;
    	int i = 0;
    	while(i < nums.length){
    		sum += nums[i];
    		if(sum >= s){
    			break;
    		}
    		i++;
    	}
    	if(i == nums.length)
    		return 0;
    	min = i+1;
        for(i = min; i < nums.length; i ++){
        	if(nums[i] >= s){
        		min = 1;
        		return min;
        	}
        	else{
        		sum = nums[i];
        		int j = i-1;
        		while(sum < s){
        			sum += nums[j];
        			j--;
        		}
        		if(i -j < min){
        			min = i-j;
        		}
        	}
        }
        return min;
    }
}