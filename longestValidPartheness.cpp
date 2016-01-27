
#include <iostream>
#include <fstream>

#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;
        int len = 0;
        vector<int> rIndex;
        vector<int> lIndex;
        for(int i = 0;i  < s.size(); i++){
            if(s[i] == '('){
                sta.push(i);
            }
            else if(s[i] == ')'){
                if(sta.empty())
                    continue;
                else {
                    int index = sta.top();
                    sta.pop();
                    lIndex.push_back(index);
                    rIndex.push_back(i);
                }
            }
            
        }
        int right,left,tmp;
        right = -1;
        left = INT_MAX;
        tmp =0;
        if(!rIndex.empty()){
            for(int i = rIndex.size()-1; i >=0; i--){
                if(left <rIndex[i]) continue;
                if(left == rIndex[i]+1){
                    right = rIndex[i];
                    left = lIndex[i];
                    tmp += right-left+1;
                    if (tmp > len)
                        len = tmp;
                }
                else{
                    tmp =0 ;
                    right = rIndex[i];
                    left = lIndex[i];
                    tmp = tmp>right-left+1?tmp:right+1-left;
                    len = tmp>len?tmp:len;
                }
            }
        }
        return len;
    }
};
int main(){
    Solution sol;
    cout<<sol.longestValidParentheses(")()())()()(");
    
    
}
