#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
    	if(nums.size() == 0){
    		return 0;
    	}
    	vector<int> maxProfit;
    	for(int i = 0;i < nums.size(); i++){
    		if(i == 0){
    			maxProfit.push_back(nums[0]);
    		}
    		else if(i == 1){
    			maxProfit.push_back(max(nums[0],nums[1]);
    		}
    		else{
    			maxProfit.push_back(max(maxProfit[i-1],maxProfit[i-2] + nums[i]));	
    		}
    	}
    	return maxProfit[nums.size()-1];
    }

};