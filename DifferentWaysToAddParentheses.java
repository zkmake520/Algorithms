public class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new ArrayList<Integer>();
        if(input.length() == 1){
        	res.add(Integer.parseInt(input[0]));
        	return res;
        }
        for(int i = 0; i < input.length();i++){
        	char c = input.charAt(i);
        	if( c< '0' || c>'9'){
        		List<Integer> res1 = diffWaysToCompute(input.substring(0,i));
        		List<Integer> res2 = diffWaysToCompute(input.subString(i+1,input.length));
        		for(int j =0; j < res1.size(); j++){
        			for(int k = 0; k < res2.size();k++){
        				if(c =='*'){
        					res.add(res1.get(j) * res2.get(k));
        				}
        				else if(c== '+'){
        					res.add(res1.get(j)+res2.get(k));
        				}
        				else{
        					res.add(res1.get(j)-res2.get(k));
        				}
        			}
        		}
         	}
        }
        return res;
    }

}