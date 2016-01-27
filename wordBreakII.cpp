#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_set>
#include<string>;
using namespace std;

class Solution{
public:
    vector<string>  wordBreak(string s, unordered_set<string> &dict) { //这边不能记录所有可能的字符串，而是应该先把位置，记录下来，再回溯
        vector<bool> dp(s.size()+1,false);
        vector<string> solution;
        vector<vector<int>> sol(s.size()+1,vector<int>());
        dp[0] = true;

        for(int i = 1;i <= s.size();i++){
            for(int j = i-1; j >=0; j--){
                unordered_set<string>:: iterator iter = dict.find(s.substr(j,i-j));
                if( iter != dict.end() && dp[j] == true){
                    sol[i].push_back(j);
                    dp[i] = true;
                }
            }
        }
        solution = getString(sol,s,s.size());
        return solution;
    }
    vector<string> getString(vector<vector<int>> sol,string s,int size){
        vector<string > whole;
        vector<string> sub;
        if(size == 0)
            return sub;
        for(int i = 0; i< sol[size].size();i++){
            sub= getString(sol,s,sol[size][i]);
            if(sub.size() != 0){
                for(int j = 0; j < sub.size();j++){
                    string tmp = sub[j];
                    tmp.append(" "+s.substr(sol[size][i],size-sol[size][i]));
                    whole.push_back(tmp);
                }
            }
            else    whole.push_back(s.substr(0,size));
        }
        return whole;
    }
};
int main(){
    Solution sol;
    unordered_set<string> dict;
    dict.emplace("abc");
    dict.emplace("ab");
    dict.emplace("c");
    dict.emplace("df");
    string s = "abcdf";

    sol.wordBreak(s,dict);

}

