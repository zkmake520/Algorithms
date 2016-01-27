public class Solution {
    public int maxSubArray(int[] nums) {
        int res = 0;
        int pos = 0;
        for(int i = 0; i < nums.length;i++){
        	if(i == 0){
        		res = nums[0];
        		pos = 0;
        	}
        	else{
        		if( nums[i] <= 0){
        			continue;
        		}
        		else{
        			int tmp = 0 ;
        			int j  = i;
        			while(num[j] >= 0 && j > pos){
        				tmp += nums[j];
        				j--;
        			}
        			if( j == pos+1){
        				tmp = tmp+res;
        			}
        			if(tmp > res){
        				res= tmp;
        				pos = i;
        			}
        		}
        	}
        }
        return res;
    }
}