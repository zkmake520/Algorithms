public class Solution {
    public int findKthLargest(int[] nums, int k) {
    	List<Integer> list = new ArrayList<>();
    	for(int i = 0; i < nums.length; i++){
    		list.add(nums[i]);
    	}
		return find(list,k);
	}
	private int find(List<Integer> nums,int k){
		int std = nums[0];
		List<Integer> right = ArrayList<Integer>();
		List<Integer> left = ArrayList<>();
		for(int i = 1; i < nums.length;i++){
			if(nums[i] >= std){
				right.add(nums[i]);
			}
			else{
				left.add(nums[i]);
			}
		}
		if(right.size() == k-1){
			return std;
		}
		else if(right.size() >k-1){
			
			return findKthLargest(right,k);
		}
		else{
			return findKthLargest(left,k-right.size()-1);
		}
    }

}