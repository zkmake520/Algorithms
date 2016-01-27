#include<iostream>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    //so strange if use dp[1000][1000] got TLE,when use vector<> right!
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp (len1+1,vector<int>(len2+1));
        if(len1 == 0)   return len2;
        if(len2 == 0)   return len1;
        for(int i =0; i <= len1;i++){
            dp[i][0] = i;
        }
        for(int i = 0; i<=len2;i++)
            dp[0][i] = i;
        for(int i = 1; i<=len1;i++){
            for(int j = 1; j <= len2;j++){
                int aa = word1[i-1]==word2[j-1]?0:1;
                int temp = min(dp[i-1][j]+1,dp[i][j-1]+1);
                int temp2 = dp[i-1][j-1]+aa;
                dp[i][j] = min(temp,temp2);
            }
        }
        return dp[len1][len2];
        
    }
    
};
int main(){
    
    
    Solution sol;
    cout<<sol.minDistance("acdf", "acdda");
    
    
}

