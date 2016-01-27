public class Solution {
    public List<String> summaryRanges(int[] nums) {
     	int len = nums.length;
     	List<String> res = new ArrayList<>();
     	if(len == 0){
     		return res;
     	}
     	int start = nums[0];
     	int cur = nums[0];
     	int continueLength = 1;
     	for(int i = 1; i < len; i ++){
     		if(nums[i] == cur +1){
     			cur = nums[i];
     			continueLength++;
     		}
     		else{
     			if(continueLength == 1){
     				String string = new String(""+cur);
     				res.add(string);
     			}
     			else{
     				String string = new String(start+"->"+cur);
     				res.add(string);
     			}
     			start = nums[i];
     			cur = nums[i];
     			continueLength = 1;
     		}

     	}   
     	if(continueLength ==1){
     		String string = new String(""+cur);
     				res.add(string);
     	}
     	else{
     		String string = new String(start+"->"+cur);
     				res.add(string);
     	}
     	return res;
    }
}