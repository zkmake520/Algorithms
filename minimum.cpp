#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
	int minPathSum(vector<vector<int>> &grid){
		if(grid.size() == 0)
			return 0;
		if(grid[0].size() == 0)
			return 0;
		vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
		m = grid.size();
		n = grid[0].size();
		int sum = 0;
		for(int i =0; i< m; i++){
			sum += grid[i][0];
			dp[i][0] = sum;
		}
		sum =0;
		for(int i =0; i< n; i++){
			sum += grid[0][i];
			dp[0][i] = sum;
		}
		for(int i = 1; i <m;i++){
			for (int j = 1; j < n;j++){
				dp[i][j] = dp[i-1][j] < dp[i][j-1]?dp[i-1][j]+grid[i][j]:dp[i][j-1]+grid[i][j];
			}
		}
		return dp[m-1][n-1];
	}


};