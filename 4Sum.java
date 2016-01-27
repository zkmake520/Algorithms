public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> rst = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for(int i = 0; i< nums.length-3;i++){
        	for(int j = j+1; j < nums.length -2; j++){
        		int sum = nums[i]+num[j];	
        		int left = target - sum;
        		int p1 = j+1;
        		int p2 = nums.length-1;
        		while(p1 < p2){
        			int n1 = nums[p1];
        			int n2 = nums[p2];
        			if(n1 + n2 == left){
		        		List<Integer> entry = new ArrayList<Integer>();
		        		entry.add(nums[i],nums[j],n1,n2);
		        		p1++;
		        		p2--;
        			}
        			else if(n1 + n2 < left){
        				p1++;
        			}
        			else{
        				p2--;
        			}
        		}
        	}
        }
    }

}