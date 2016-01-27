public class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        StringBuilder res = new StringBuilder();
        int integer = numerator / denominator;
        int left = numerator - denominator*integer;
        res.append(""+integer)
        if(left == 0){
        	return res.toString();
        }
        res.append(".");
        Map<Integer,Integer> decimalPos = new HashMap<>();
        int pos = 0;
        ArrayList<Character> decimals = new ArrayList<>();
        int recurStart = -1;
        while(true){
        	if(left == 0){
        		break;
        	}
        	if(decimalPos.containsKey(left)){
        		recurStart = decimalPos.get(left);
        		decimals.add(')');
        		break;
        	}
        	decimalPos.put(left,pos);
        	while(left < denominator){
        		left = left*10;
        	}
        	int num = left / denominator;
        	left = left % denominator;
        	char c = num+'0';
        	decimals.add(c);
        }
        if(recurStart == -1){
        	for(int i = 0; i < decimals.size() ; i++){
        		res.append(""+decimals.get(i));
        	}
        }
        else{
        	for(int i = 0 ; i< decimals.size(); i++){
        		if(i == recurStart){
        			res.append("(");
        		}
        	}
        }
        return res.toString();
    }
}