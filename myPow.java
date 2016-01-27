public class Solution {
    public double myPow(double x, int n) {
        double res = x;
        int count = 1;
        HashMap<Double,Integer> variables = new HashMap<>();
        if(n == 0){
        	return 1;
        }
        List<Double> tmp = new ArrayList<Double>();
        int sign = 1;
        if(n < 0){
        	sign = -1;
        	n = -n;
        }
        while(count != n){
        	count = count*2;
        	if(count > n){
        		n = n - count/2;
        		count = count/4;
        		tmp.add(res);
        		if(count == 1){
        			res = x;
        		}
        		else {
        			res = variables.get(count);
        		}
        	}
        	else{
        		res = res*res;
    		}
        	variables.put(res,count);
        }
        res = 1;
        for(int i = 0; i< tmp.size();i++){
        	res *=tmp.get(i);
        }
       	if(sign == -1){
       		return 1/res;
       	}
        return res;

    }
}