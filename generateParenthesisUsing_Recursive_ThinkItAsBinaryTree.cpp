//
//  generateParenthesisUsing_Recursive_ThinkItAsBinaryTree.cpp
//  
//
//  Created by zkwangchao on 14-4-9.
//
//
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        getParenthesis(ans,"",0,0,n);
        return ans;
    }
    void getParenthesis(vector<string> &ans,string s, int l, int r,int n)
    {
        if(l == n){
            ans.push_back(s.append(n-r,')'));
            return;
        }
        getParenthesis(ans, s+"(", l+1, r, n);
        if(l >r)
            getParenthesis(ans, s+")", l, r+1, n);
    }
};