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
    string longestPalindrome(string s) {
        string newS;
        int max = -1;
        int maxId = -1;
        newS.push_back('#');
        
        for(int i = 0 ; i < s.size();i++){
            newS.push_back(s[i]);
            newS.push_back('#');
        }
        //  cout<<newS<<endl;
        vector<int> P(newS.size()+1, 0);
        for(int i = 0; i < newS.size();i++){
            int len = 1;
            if(i > max){
                while( i+len <= newS.size()-1 && i-len>=0&&newS[i+len] == newS[i-len]){
                    len++;
                }
                P[i] = len;
                
                if(len+i-1 > max){
                    max = len+i-1;
                    maxId = i;
                }
            }
            else{
                if(P[2*maxId - i] <= max-i)
                    P[i] = P[2*maxId-i];
                else{
                    while(max+len <= newS.size()-1 && 2*i-max-len>=0&&newS[max+len ] == newS[2*i-max-len])
                        len++;
                    P[i] = max-i+len;
                    if(P[i]-1+i >max){
                        max = i+P[i]-1;
                        maxId = i;
                    }
                }
            }
        }
        string ans;
        int j = 0;//cout<<max<<endl;
        int num = 0;
        for(int i = 0; i < newS.size();i++)
        {
            cout<<P[i]<<endl;
            if(P[i] > num)
            {
                num = P[i];
                j = i;
            }
        }
        cout<<j<<num<<endl;
        for(int i = j-num+1; i < j+num;i++){
            if(newS[i] != '#')
                ans.push_back(newS[i]);
        }
        
        return ans;
    }
};
int main(){
    
    Solution sol;
    // cout<<2<<endl;
    string ans = sol.longestPalindrome("aaa");
    cout<<ans;
    
}