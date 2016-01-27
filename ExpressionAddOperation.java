public class Solution {
    public List<String> addOperators(String num, int target) {
    	List<String> res = new ArrayList<String>();
    	helper(res,num,0,target,0,0,"");
    	return res;
    }
    private void helper(List<String> res, String num, int pos,int target,int eval,int mlt,String path,int sign){
    	if(pos == num.length){
    		if(target == eval){
    			res.add(path);
    		}
    		return;
    	}

    	for(int i = pos; i < num.length; i++){
    		if(num.charAt(pos) == '0' && i> pos){
    			break;
    		}
    		long cur = Long.parseLong(num.subString(pos,i+1));
    		if(pos == 0){
    			helper(res,num,i+1,target,cur,cur,path+cur,1);
    		}
    		else{
    			helper(res,num,i+1,target,eval+cur,cur,path+"+"+cur,1);
    			helper(res,num,i+1,target,eval-cur,cur,path+"-"+cur,-1);
    			helper(res,num,i+1,target,eval-sign*mlt+sign*cur*mlt,mlt*cur,path+"*"+cur,sign);
    		}
    	}
    }
}