public class Solution {
    public int[] singleNumber(int[] nums) {
        int [] res = new int[2];
        int sum = nums[0];
        for(int i = 1; i < nums.length;i++){
        	sum =  sum ^ nums[i];
        }
        if(sum == 0){
        	res[0] = res[1] = 0;
        	return res;
        }
        int bitLength = 1;
        int xor = 1;
        while((sum & xor) == 0){
        	xor = xor <<1;
        	bitLength++;
        }
        int sum2 = 0;
        for(int i = 0; i < nums.length; i++){
        	if(nums[i] & xor != 0){
        		sum2 = sum2 ^ nums[i];
        	}
        }
        res[0] = sum2;
        res[1] = sum2 ^ sum;
        return res;
    }
}