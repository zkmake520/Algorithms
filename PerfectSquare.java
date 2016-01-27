public class Solution {
	int res = -1;
    public int numSquares(int n) {
    	 helper(0,n);
    	 return res;
    }
    private void helper(int count, int eval){
    	if(res != -1){
    		return;
    	}
    	if(eval == 0){
			res = count;
			return;    		
    	}
    	if(eval < 0){
    		return ;
    	}
    	for(int i = eval;i>=1;i--){
    		if(i*i > eval){
    			continue;
    		}
    		else{
    			helper(count+1,eval-i*i);
    		}
    	}
    	return;
    }
}