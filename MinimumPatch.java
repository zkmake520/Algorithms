public class Solution {
    public int minPatches(int[] nums, int n) {
        int cnt = 0;
        long sum = 0;
        for(int i = 0;i < nums.length; i++){
        	while(sum+1 < nums[i] && sum < n){
        		cnt++;
        		sum += sum+1;
        	}
        	sum+= nums[i];
        	if(sum >= n){
        		break;
        	}
        }
        while(sum < n){
        	cnt++;
        	sum += sum+1;
        }
        return cnt;
        
    }
}