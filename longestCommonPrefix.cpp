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
public://关键在于两两比较，用得到的prefix和别的串在进行比较
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if(strs.size() == 0)    return "";
        if(strs.size() == 1)    return strs[0];
        
        for(int i = 0; i < min(strs[0].size(), strs[1].size()); i++){
            if(strs[0][i] == strs[1][i])
                prefix.push_back(strs[0][i]);
            else break;
        }
        
        for(int i = 2; i < strs.size();i++){
            if(strs[i].empty()) return "";
            for(int j = 0; j < min(strs[i].size(), prefix.size());j++){
                if(prefix[j] != strs[i][j]){
                    
                    break;
                }
            }
            prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};
int main ()
{
    string s1 = "0";
    string s2 = "12";
    string s3 = "";
    vector<string> A;
    A.push_back("");
    A.push_back("");
    A.push_back("a");
    Solution sol;
    cout<< sol.longestCommonPrefix(A);
    
    
}

