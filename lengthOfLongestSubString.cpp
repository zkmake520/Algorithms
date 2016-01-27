//
//  lengthOfLongestSubString.cpp
//  
//
//  Created by zkwangchao on 14-4-8.
//
//

#include "lengthOfLongestSubString.h"
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength =0 ;
        int cur = 0;
        unordered_map<string,int>mp;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]]  = i;
                cur++;
            }
            else{
                if(cur > maxLength)
                    maxLength = cur;
                cur  = i -mp[s[i]];
                mp[s[i]] = i;
            }
        }
        return maxLength;
        
    }
};
int main(){
    
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("abcabcbb");
}