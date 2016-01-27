public class Solution {
    public int nthUglyNumber(int n) {
        int twoCount=1, threeCount = 1, fiveCount = 1;
        int count = 1;
        int num = 1;
        int [] intermidate = new int[n+1];
        intermidate[1] = 1;
        for(int i = 2; i <= n;i ++){
        	intermidate[i] = Math.min(intermidate[twoCount]*2,Math.min(intermidate[threeCount]*3,intermidate[fiveCount]*5));
        	if(intermidate[i] == intermidate[twoCount]*2){
        		twoCount++;
        	}
        	if(intermidate[i] == intermidate[threeCount]*3){
        		threeCount++;
        	}
        	else{
        		fiveCount++;
        	}
        }
        return intermidate[n];
    }
}