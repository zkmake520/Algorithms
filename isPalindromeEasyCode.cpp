
#include<iostream>
#include<vector>
#include<unordered_map>
#include <ctype.h>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
s=s.toLowerCase();
    s=s.replaceAll("[^0-9a-zA-Z]", "");
    char c[]=s.toCharArray();
    int counthead=0,counttail=s.length()-1;
    while(counthead<=s.length()-1&&counttail>=0){
        if(c[counthead]!=c[counttail]) return false;
        counthead++;
        counttail--;
    }
    return true;
    }
};
int main(){
    Solution sol;
    cout<<sol.isPalindrome(".,");
}
