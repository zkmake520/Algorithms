public class Solution {
    public boolean isUgly(int num) {
        int[] factor = new int[]{2,3,5};
        boolean flag = false;
        while(num != 1){
        	flag = false;
        	for(int i=0 ; i < factor.length; i ++){
        		if(num % factor[i] == ){
        			num = num/factor[i];
        			flag = true;
        		}
        	}
        	if(!flag){
        		break;
        	}
        }
        if(num == 1){
        	return true;
        }
        else{
        	return false;
        }
    }
}