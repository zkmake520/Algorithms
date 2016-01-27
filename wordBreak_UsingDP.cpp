#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_set>
#include<string>;
using namespace std;

class Solution{
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i = 1;i <= s.size();i++){
            for(int j = i-1; j >=0; j--){
                unordered_set<string>:: iterator iter = dict.find(s.substr(j,i-j));
                if( iter != dict.end() && dp[j] == true) {dp[i] = true;break;}
            }
        }
      //  for(int i = 0; i <= s.size();i++)
      //  cout<<dp[i]<<endl;
        return dp[s.size()];
    }
};
int main(){
   Solution sol;
    unordered_set<string> dict;

   dict.emplace("abc");

    dict.emplace("df");
    string s = "abcdf";

    sol.wordBreak(s,dict);

}
