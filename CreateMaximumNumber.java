public class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
    	int[] rst;
    	int max = -1;
    	for(int i = 0;i <= k; i++){
    		if(i > nums1.length || (k-i) > nums2.length){
    			continue;
    		}
    		else{
    			int[] tmp = merge(maxArray(i,nums1),maxArray(k-i,nums2),k);
    			rst = max < getNumber(tmp)?tmp,rst;
    		}
    	}
    	return rst;
    }
    public int getNumber(int [] nums){
    	int num = 0;
    	for(int i = 0; i <nums.length;i++){
    		num = num * 10+nums[i];
    	}
    	return num;
    }
    public int[] maxArray(int k, int [] nums){
    	Stack<Integer> stack = new Stack<>();
    	for(int i = 0;i < nums.length;i++){
    		int num = nums[i];
    		while(!stack.isEmpty() && num > stack.peek() && (nums.length-i-1+stack.size()) > k){
    			stack.pop();
    		}
    		if(stack.size() < k){
    			stack.push(num);
    		}
    	}
    	int[] rst = new int[k];

        for(int i = k-1; i >= 0; i--){
        	rst[i] = stack.pop();

        }
        return rst;

    }
    public int[]  merge(int[]nums1,int[] nums2,k){
    	int size = 0;
        Stack<Integer> stack = new Stack<>();
        int i =0, j =0;
        while(i < nums1.length || j < nums2.length){
        	int nums = 0;
        	if(i < nums1.length && j < nums2.length){
        		int m = i;
        		int n = j;
	        	while(m < nums1.length && n < nums2.length && nums1[m] == nums2[n]){
	        		m++;n++;
	        	}
	        	if(m < nums1.length && n < nums2.length){
	        		if(nums1[m] > nums2[n]){
	        			nums = nums1[i];
	        			i++;
	        		}
	        		else{
	        			nums = nums2[j];
	        			j++;
	        		}

	        	}
	        	else if(m < nums1.length){
	        		nums = nums1[i];
	        		i++;
	        	}
	        	else{
	        		nums = nums2[j];
	        		j++;
	        	}
	        }
	        else if( j < nums2.length){
	        	nums = nums2[j];
	        	j++;
	        }
	        else{
	        	nums = nun1[i];
	        	i++;
	        }
	        while(!stack.isEmpty() && nums > stack.peek() && (stack.size()+nums1.length+nums2.length-i-j) >= k){
	        	stack.pop();
	        }
	        if(stack.size() < k){
	        	stack.push(nums);
	        }
        }
        int[] rst = new int[k];

        for(int i = k-1; i >= 0; i--){
        	rst[i] = stack.pop();

        }
        return rst;

    }
}