public class Solution {
    public int singleNumber(int[] nums) {
     	int bitCount = 0;   
     	int res = 0;
     	for(int i = 0; i < 32 ;i++){
     		for(int j = 0;j < nums.length; j++){
     			bitCount += 1&(nums[j] >>i);
     		}
     		if(bitCount %3 != 0){
     			res = res | (1<<i);
     		}
     	}
     	return res;
    }
}