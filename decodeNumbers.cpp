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
    int check(char a,char b){
        if(a == '1' || (a == '2'&& b <= '6'))
            return 1;
        return 0;
    }
    int numDecodings(string s) {//注意可以采用递归从最后开始考虑，但是如果采用从前往后考虑是一样的，而且不用递归
        vector<int> numbers(s.size()+1,0);
        if(s.empty())   return 0;
        numbers[0] = 1;
        if(s[0] != '0') numbers[1] =1;
        else    numbers[1]= 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i] != '0') numbers[i+1] += numbers[i];
            if(check(s[i-1],s[i])) numbers[i+1] += numbers[i-1];
        }
        return numbers[s.size()];
        
    }
};
int main(){
    
    Solution sol;
    cout<<sol.numDecodings("10");
    
    
}