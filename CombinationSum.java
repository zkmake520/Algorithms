public class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
    	HashMap<Integer,Boolean> path = new HashMap<>();
    	for(int i = 1; i <=9; i++){
    		path.put(i,false);
    	}
    	List<List<Integer>> res = new ArrayList<List<Integer>>();
    	List<Integer> cur = new ArrayList<>();
		return backTrace(k,n,1,path,res,cur,0);       	
    }
    public List<List<Integer>> backTrace(int k,int n, int level,HashMap<Integer,Boolean> path,List<List<Integer>> res, List<Integer> cur,int sum){
    	if(level == k){
    		if(sum==n){
    			List<Integer> one = cur.clone();
    			res.add(one);
    		}
    	}
    	for(int i =1 ;i <= 9; i++){
    		if(path.get(i)){
    			continue;
    		}
    		else{
    			path.put(i,true);
    			sum += i;
    			cur.add(i);
    			backTrace(k,n-i,level+1,path,res,cur,sum);
    			cur.remove(cur.size()-1);
    			sum -= i;
    			path.put(i,false);
    		}
    	}
    }
}