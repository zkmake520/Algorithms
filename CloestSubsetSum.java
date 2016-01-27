public class CloestSubsetSum{
	public int getTheSumDiffer(int [] A,int m){
		//dynamic programming
		int n = A.length;
		int splitLen = n/m;
		int sum = 0;
		for(int i = 0;i < n;i ++){
			sum += A[i];
		}
		int splitSum = sum/m;
		boolean [][][] dp = new boolean[n+1][splitLen+1][splitSum+1];
		for(int k = 0; k <= splitSum; k++){
			for(int i = 0;i < n;i ++){
				for(int j = 0; j <= splitLen; j++){
					if(i == 0){
						if(j == 0 ){
							if(k == 0){	
								dp[i][j][k] = true;
							}
							else{
								dp[i][j][k] = false;
							}
						}
						else{
							dp[i][j][k] = false;
						}
					}
					else{
						if(j==0){
							dp[i][j][k]= false;
						}
						else{
							if(k >= A[i]){
								dp[i][j][k] = dp[i-1][j][k] || dp[i-1][j-1][k-A[i]];
							}
							else{
								dp[i][j][k] = dp[i-1][j][k];
							}
						}
					}
				}
			}
		}
		int min = 0;
		int i;
		for(i = splitSum; i>=0; i--){
			if(dp[n-1][splitLen][i]){
				min = i; 
			}
		}
		return splitSum - i;
	}	
	public static void main(String[] args){
		CloestSubsetSum sol = new CloestSubsetSum();
		int [] A= new int[] {2,3,4,1,5,6,7,1,9};
		System.out.println(sol.getTheSumDiffer(A,2));
	}
}