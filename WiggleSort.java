public class Solution {
    public void wiggleSort(int[] nums) {
    	//find kth largest according to l , thus k is the array idx, is the distance from l 
        int x = findMedian(nums,0,nums.length-1; (nums.length-1)/2);
        int idx = 1;
        for(int i = 0; i< nums.length;i++){
        	if(nums[i] > num){
        		int tmp = nums[i];
    			nums[i] = nums[idx];
    			nums[idx] = i;
    			idx+=2;
        	}
        }
        return;
    }
    public int findMedian(int[] nums,int l, int r, int k){
    	int idx = partition(nums,l,r);
    	if(idx-l-1 == k){
    		return nums[idx];
    	}
    	else if(idx-l-1 > k){
    		return findMedian(nums,l,idx-1,k);	
    	}
    	else{
    		return findMedian(nums,idx,r,k-(idx-l)+1);
    	}

    }	
    //after partition the pivot is at nums[idx]
    public int partition(int[]nums,int l,int r){
    	int x =  nums[r], idx = l;
    	for(int i  = l;i <= r; i++){
    		if(nums[i] <= x){
    			int tmp = nums[i];
    			nums[i] = nums[idx];
    			nums[idx] = i;
    			idx++;
    		}
    	}
    	return idx;
    }

}