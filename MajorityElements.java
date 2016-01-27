public class Solution {
    public List<Integer> majorityElement(int[] nums) {
    	List<Integer> list = new ArrayList<Integer>();
    	int len = nums.length;
    	if(len == 1){
    		list.add(nums[0]);
    		return list;
    	}
    	//using moore's voting algorithm.
    	//c1, c2 , if ==0, then new element occupy this pos
    	//else if num ==, then c++, else c--;
        int c1 = 0;
        int c2 = 0;
        int m1 = Integer.MAX_VALUE;
        int m2 = Integer.MIN_VALUE;
        for(int i = 0 ;i < len;i++){
        	if(nums[i] == m1){
        		c1++;
        	}	
        	else if(nums[i] == m2){
        		c2++;
        	}
        	else if(c1 == 0){
        		c1++;
        		m1 = nums[i];
        	}
        	else if(c2 == 0){
        		c2++;
        		m2 = nums[i];
        	}
        	else{
        		c1--;
        		c2--;
        	}
        }
        c1=c2=0;
        for(int i = 0;i < len;i++){
        	if(nums[i] == m1){
        		c1++;
        	}
        	if(nums[i] == m2){
        		c2++;
        	}
        }
        if(c1 > len/3){
        	list.add(m1);
        }
        if(c2 > len/3){
        	if(m1!=m2){
        		list.add(m2);
        	}
        }
        return list;
    }
}