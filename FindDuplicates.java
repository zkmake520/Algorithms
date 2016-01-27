public class Solution {
    public int findDuplicate(int[] nums) {
        //using binary search
        int e = nums.length;
        int s = 1;
        while( s < e){
        	mid = e+(e-s)/2;
        	count = 0 ;
        	for(int num:nums){
        		if (num <= mid){
        			count++;
        		}
        	}
        	if(count <= mid){
        		s = mid+1;
        	}
        	else{
        		e = mid;
        	}
        }
        return s;
    }
}