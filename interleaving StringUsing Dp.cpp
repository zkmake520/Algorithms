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
public://注意点：不能直接判断dp[0][i] = 1，还是要根据字符串进行判断
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1));
        if(s1.length()+s2.length() != s3.length())  return false;
        dp[0][0] = 1;
        for(int i = 1; i <= len1; i++){
            if(dp[i-1][0] == 1&& s1[i-1] == s3[i-1])
                dp[i][0] = 1;
        }
        for(int i = 1; i <= len2; i++){
            if(dp[0][i-1] == 1&& s2[i-1] == s3[i-1])
                dp[0][i] = 1;
        }
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if((dp[i-1][j] == 1 && s1[i-1] == s3[i+j-1])|| (dp[i][j-1] == 1&& s2[j-1] == s3[i+j-1]))
                    dp[i][j] = 1;
            }
        }
        return dp[len1][len2] == 1?true:false;
    }
};
int main ()
{
    string s1 = "a";
    string s2 = "";
    string s3 = "c";
    Solution sol;
    
    cout<< sol.isInterleave(s1, s2, s3);
    
    
}

