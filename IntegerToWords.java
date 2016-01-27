public class Solution {
    public String numberToWords(int num) {
        String [] base = new String[]{"Thousand","Million","Billion"};
        String [] nums = new String[]{"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        String [] tens = new String[]{"Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninty"};
        List<String> list = new ArrayList<>();
        int len = 0;
        while(num != 0){
        	int digit = num % 10;
        	num = num /10;	
        	if((len/3-1) >= 0 && (len % 3 == 0)){
        		build.add(" "+base[len/3-1]);
        	}
        	if(digit >=1){
        	    if(len % 3== 0)
        	        build.add(" "+nums[digit-1]);
        	    else if (len % 3==1){
        	        build.add(" "+tens[digit-1]);
        	    }
        	    else {
        	        build.add(" Hundred");
        	        build.add(" "+nums[digit-1]);
        	    }
        	   
        	}
        	len ++;
        }
        StringBuffer buffer = new StringBuffer();
        for(int i = list.size()-1; i >=0;i--){
        	buffer.append(list.get(i));
        	buffer.append(" ");
        }
        return buffer.toString().trim();
        
    }
}