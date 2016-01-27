public class Solution {
    public int maxProfit(int k, int[] prices) {
    	int n = prices.length;
    	//dp means the max profit that last transaction is on i's day and at most k transactions
        int [][] dp = new int[n+1][k+1];
        for(int i = 0;i <= n; i++){
        	dp[i][0] = 0;
        }
        for(int i = 0; i <=k; i++){
        	dp[0][k] = 0;
        }
        for(int i = 1; i <=n;i++){
        	for(int j = 1; j <= k; j++){
        		dp[i][j] = Math.max(dp[i][j-1],0);
        		for(int m = 1; m <= i -1; m++){
        			dp[i][j] = Math.max(dp[i][j],dp[m][j-1]+ getProfit(prices,m-1,i-1));
        		}
        	}
        }
        int max = Integer.MIN_VALUE;
        for(int i =0; i <=n;i++){
        	max = Math.max(max,dp[i][k]);
        }
        return max;
    }
    int getProfit(int [] A, int s, int e){
    	int min = Integer.MAX_VALUE;
    	int max = Integer.MIN_VALUE;
    	for(int i = s; i <= e;i++){
    		min = Math.min(A[i],min);
    		max = Maht.max(max,A[i]-min);
    	}
    	return max;
    }
}