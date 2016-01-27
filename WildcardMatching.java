public class WildcardMatching{
	public boolean isMatch(String s, String p) {
		int starIndex = -1;
		int sIndex = 0; 
		for(int i = 0,j = 0;i < s.length(); ){
			if(j >= p.length()){
				return false;
			}
			if(p.charAt(j) == '?' || p.charAt(j) == s.charAt(i)){
				i++;
				j++;
			}
			else if(p.charAt(j) == '*'){
				starIndex = j++;
				sIndex = i;
			}
			else if(starIndex != -1){
				i = ++sIndex;
				j = starIndex+1;
			}
			else{
				return false;
			}
		}
		while(j < p.length()){
			if(p.charAt(j) != '*'){
				return false;
			}
		}
		return true;
	}
}