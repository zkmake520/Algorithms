#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minCut(string s) {   //这边要注意了。如何判断i -j是不会回文，不能每次都比较一边，因为也可以用dp！！！
        vector<int> dp(s.size()+1, INT_MAX);
        vector<vector<int>> g(s.size()+1, vector<int>(s.size()+1,0));
        dp[0] = -1;
        g[0][0] = 1;
        for(int i= 1; i<= s.size();i++){
            for(int j = i-1;j >=0; j--){
                if(s[i-1] == s[j] && (i-1-j<2 || g[j+1][i-2]== 1)){ //dp
                    g[j][i-1] =1;
                    dp[i] = dp[j]+1 < dp[i]?dp[j]+1:dp[i];
                }
            }

        }
        return dp[s.size()];
    }

};
int main(){
    Solution sol;
    cout<<sol.minCut("abbab");

}
