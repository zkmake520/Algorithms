//
//  lengthOfLongestSubString.cpp
//
//
//  Created by zkwangchao on 14-4-8.
//
//

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string countAndSay(int n){
        string say;
        string tmp;
        if(n == 0)  return "";
        say = "1";
        for(int i = 1; i < n; i++){
            tmp.clear();
            for(int j = 0; j < say.length(); j++){
                int count = 0;
                while(j+1 < say.length() && say[j] == say[j+1]) count++,j++;
                tmp.push_back('1'+count);
                tmp.push_back(say[j]);
            }
            say = tmp;
        }
        return say;
    }
};
int main(){
    
    Solution sol;
    cout<<sol.countAndSay(1);
    
    
}