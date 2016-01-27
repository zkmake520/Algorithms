public class Solution {
    public int findMin(int[] nums) {
        //5674123
        // 4444123
        // 5671111
        //555512355 //this is the special cases
    	return helper(nums,0,nums.length-1);
    }
    int helper(int[] A, int s, int e){
    	if(s == e){
    		return A[s];
    	}
    	int mid = s+(e-s)/2;
    	if(A[mid] > A[s]){
    		return helper(A,mid+1,e);
    	}
    	else if(A[mid] < A[s]){
    		return helper(A,s,mid);
    	}
    	else if(A[mid] == A[s]){
    		if(A[mid] > A[e]){
    			return helper(A,mid+1,e);
    		}
    		if(A[mid] == A[e]){
    			s++;
    			e--;
    			if(s > e){
    				return A[s-1];
    			}
    		}
    	}
    }
}