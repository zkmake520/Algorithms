#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<fstream>
#include<ostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;
class Solution {
    public:
    bool compare(string s1, string s2){
        int allChar [26];
        memset(allChar,0,sizeof(allChar));
        if(s1.size() != s2.size())  return false;
        for(int i = 0; i<s1.size();i++)
        allChar[s1[i]-'a']++;
        for(int i = 0; i<s2.size();i++)
        allChar[s2[i]-'a']--;
        for(int i =0; i< 26;i++){
            if(allChar[i] !=0)
            return false;
        }
        return true;
    }
    bool isScramble(string s1, string s2) {
        if(s1 == s2)return true;
        bool res = false;
        if(!compare(s1,s2)) return false;
        for(int i =1;i < s1.size();i++){
            res = isScramble(s1.substr(0,i), s2.substr(0,i)) &&
            isScramble(s1.substr(i), s2.substr(i));
            res = res|| (isScramble(s1.substr(0,i),s2.substr(s2.size()-i,i)) &&
                         isScramble(s1.substr(i), s2.substr(0,s2.size()-i)));
            if(res == true) return true;
        }
        return false;
    }
    
};

int main(){
    Solution sol;
    cout<<sol.isScramble("xstjzkfpkggnhjzkpfjoguxvkbuopi", "xbouipkvxugojfpkzjhnggkpfkzjts");
    
}





