public class Solution {
  	public boolean isMatch(String s, String p) {
  		int starIdx = -1;
  		int sIdx = 0;
  		int i = 0,j = 0;
  		while(i < s.length()){
  			if(j < p.length() && (p.charAt(j) == '?' || p.charAt(j) == s.charAt(i)){
  				i++;
  				j++;
  			}
  			else if(j < p.length() && p.charAt(j) == '*'){
  				starIdx = j;
  				sIdx = i;
  				j++;
  			}
  			else if(starIdx != -1){
  				i = ++sIdx;
  				j = starIdx;
  				j++;
  			}
  			else{
  				return false;
  			}
  		}
  		while(j < p.length()){
  			if(p.charAt(j)!='*'){
  				return false;
  			}
  			j++;
  		}
  		return true;

	}
}