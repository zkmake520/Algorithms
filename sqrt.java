public class Solution {
 public int mySqrt(int x) {
 		if(x==1 || x== 0){
 			return x;
 		}
 		int l = 1;
 		int r = x; 
 		int num = (l+r)/2; 
        while(1){
        	int left = x/num;
        	if(left == num){
        		return num;
        	}
        	if(left>num){
        		if(x/(num+1) <num+1){
        			return num;
        		}
        		r = num;
        		num = (r+l)/2;
        	}
        	else{
        		l = num;
        		num = (r+l)/2;
        	}
        }
    }
}