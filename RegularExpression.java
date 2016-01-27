public class Solution {
    public boolean isMatch(String s, String p) {
        int i = 0, j = 0;
        while(i < s.length()){
        	if(j == p.length()){
        		return false;
        	}
        	if(s.charAt(i) == p.charAt(j) || p.charAt(j) == '.'){
        		i++;
        		j++;
        	}	
        	else{
        		if(p.charAt(j) != '*'){
        			if(j+1<p.length() && p.charAt(j+1) == '*'){
        				j+= 2;
        				i++;
        			}
        			else{
        				return false;
        			}
        		}
        		else{
        			while(j-1 >= 0 && i < s.length() && (p.charAt(j-1) == s.charAt(i++) || p.charAt(j-1)=='.')){
        				if(isMatch(s.substring(i,s.length())),p.substring(j+1,p.length())){
        					return true;
        				}
        			}
        			return false;
        		}
        	}
        }
        // if(j < p.length()){
        // 	while(j < p.length()){
        // 		if(p.charAt(j) != '*'){
        // 			return  false;
        // 		}
        // 		j++;
        // 	}
        // }
        // return true;

    }
}