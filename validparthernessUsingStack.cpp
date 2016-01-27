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
public:
    bool isValid(string s){
        stack<char> sta;
        if(s.size() == 0)return true;
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '('||s[i] == '{'||s[i] == '[')
                sta.push(s[i]);
            else{
                char temp = sta.top();
                if(temp == '(' && s[i] !=')')
                    return false;
                else if(temp == '{' && s[i] !='}')
                    return false;
                else if(temp == '['&&s[i] !=']')
                    return false;
                sta.pop();
            }
        }
        if(sta.empty())return true;
        return false;
    }
};
int main(){
    
    
    Solution sol;
    vector<string> A;
    A.push_back("foo");
    A.push_back("bar");
    cout<<sol.isValid("[(){}[]]");
    //for(int i=0; i <res.size();i++)
    //  cout<<res[i];
    
    
}

