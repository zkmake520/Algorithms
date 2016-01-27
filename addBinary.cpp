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
    string addBinary(string a, string b) {
        if(a.empty() && b.empty()) return "";
        if(a.empty())   return b;
        if(b.empty())   return a;
        int advanced = 0;
        string res;
        if(a.length() < b.length()){
            string c = b;
            b = a;
            a = c;
        }
        int j = b.length()-1;
        for(int i = a.length()-1 ; i >=0 ;i--,j--){
            if(j < 0){
                res.push_back('0'+((a[i]-'0') ^ advanced));
                advanced =(a[i]-'0') & advanced;
            }
            else{
                res.push_back('0'+((a[i]-'0') ^(b[j] - '0') ^ advanced));
                //  cout<<res<<endl;
                advanced = ((a[i]-'0')+ (b[j]-'0')+advanced >1)?1:0;
            }
        }
        if(advanced == 1)   res.push_back('1');
        string ret;
        for(int i = res.length()-1; i >= 0;i--)
            ret.push_back(res[i]);
        return ret;
    }
};
int main(){
    
    Solution sol;
    // cout<<1<<endl;
    cout<<sol.addBinary("1101","111" );
    
    
}