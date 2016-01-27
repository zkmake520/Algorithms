public class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> queue = new Priority<>(Collections.reverseOrder());
        for(int i = 0 ;i < nums.length; i++){
        	queue.add(nums[i]);
        }
        int res = 0;
        for(int i = 0;i < k; i++){
        	res = queue.poll();
        }

        return res;
    }
}