#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {  //注意第二层循环，是从尾部开始的！
            vector<int> dp(T.size()+1,0);
            dp[0] =1;   //不是0
            for(int i = 0; i< S.size(); i++){
                for(int j = T.size()-1; j >= 0;j--){
                    if(S[i] == T[j]){
                        dp[j+1] += dp[j];
                    }
                }
            }
            return dp[T.size()];
        }
};
int main(){
    string S = "b";
    string t= "b";
    Solution sol;
    cout<<sol.numDistinct(S,t);
}
