public class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        long [] sums = new long[nums];
        int sum = 0;
        for(int i = 0;i < nums.length; i++){
        	sum += nums[i];
        	sums[i] = sum;
        }
        return helper(sums,nums,0,nums.length-1, lower, upper);
    }
    int helper(long[] sums,int [] nums,int s, int e,int lower,int upper){
    	if(s==e){
    		if(sums[s] >= lower && sums[s] <= upper){
    			return 1;
    		}
    		return 0;
    	}
    	int mid = s+ (e-s)/2;
    	int cnt = helper(sums,nums,s,mid,lower,upper) + helper(sums,nums,mid+1,e,lower,upper);
    	/**
    	 * begin merge part
    	 */
    	int i,l = mid+1, u = mid+1,k = mid+1;
    	int [] copy = new int[e-s+1];
    	int innerIdx = 0;
    	for(i = s; i <= mid; i++){
    		while(l <= e && sums[l]- sums[i] < lower){
    			l++;
    		}
    		while(u <= e && sums[u] -sums[i] <= upper){
    			u++;
    		}
    		cnt += u-l;
    		while(k <=e && sums[k] < sums[i]){
    			copy[innerIdx++] = sums[k];
    		}
    		copy[innerIdx++] = sums[i];

    	}
    	return cnt;

    }
}