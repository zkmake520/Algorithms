public class CoinChange{
	public int coinChange(int[] coins,int amount){
		int[] rst = new int[amount+1];
		rst[0] = 0;
		for(int i = 1;i <= amount; i++){
			int min = Integer.MAX_VALUE;
			for(int j = 0; j < coins.length;j++){
				if(i - coins[j] < 0 || rst[i-coins[j]] == -1){
					continue;	
				}
				else{
				    
					min = Math.min(min,rst[i-coins[j]]+1);
				}
			}

			rst[i] = min == Integer.MAX_VALUE?-1:min;
		}
		return rst[amount];
	}
}