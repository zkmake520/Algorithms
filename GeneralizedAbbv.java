import java.util.*;
public class GeneralizedAbbv {
    public List<String> generateAbbreviations(String word) {
        List<String> rst = new ArrayList<String>();
        rst.add(word);
        for(int i = 0;i < word.length(); i++){
	        addAbb(word,i,rst);
	    }
	    for(int i = 0;i < rst.size(); i++){
	    	System.out.println(rst.get(i));
	    }
	    return rst;

    }
    public void addAbb(String word, int index,List<String> rst){
    	if(index == word.length()){
    		return;
    	}
    	char pre= '\0';
    	String abbv = "";
    	boolean preProcessed = false;
    	int idx = index;
    	if(index >= 1){
    		int numEnd = index-1;
    		int numStart = index-1;
    		while(numStart >=0 && '0'<=word.charAt(numStart) && '9'>= word.charAt(numStart)){
    			numStart--;
    		}
    		if(numStart != numEnd){	
				abbv = word.substring(0,numStart+1);
				int num = Integer.parseInt(word.substring(numStart+1,numEnd+1));
				// if(num >=10 ){
				// 	System.out.println(abbv);
				// }
				abbv += Integer.toString(num+1);
				//here notice that the number could exceed 9 , can't simply take it as 0-9
				// if(num >=10 ){
				// 	System.out.println(abbv+":"+num);
				// }
				idx = abbv.length();
				abbv+=word.substring(index+1,word.length());	
				rst.add(abbv);	
				preProcessed = true;
			}  	
    	}
    	if(preProcessed == false){
    		abbv = word.substring(0,index);
    		idx = index+1;
    		abbv += "1" + word.substring(index+1,word.length());
    		rst.add(abbv);
    	}
    	for(int i = idx; i < abbv.length(); i++){
    		addAbb(abbv,i,rst);
    	}
    }
    public  static void main(String[] args){
    	GeneralizedAbbv sol = new GeneralizedAbbv();
    	sol.generateAbbreviations("wordwordword");
    }

}