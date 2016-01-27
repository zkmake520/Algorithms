#include<iostream>
#include<vector>
#include<unordered_map>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        for(int i =0, j = s.size()-1; i<j; ){
            while(isdigit(s[i]) == 0 && isalpha(s[i]) == 0){
                i++;
                if(i>=s.size())
                    return true;

            }
             while(isdigit(s[j]) == 0 && isalpha(s[j]) == 0){
                j--;
                if(j <0) return true;

            }
            if(tolower(s[i]) != tolower(s[j]))
            {
               /* cout<<s.size()<<endl;
                cout<<i<<endl;
                  cout<<j<<endl;*/
                return false;

            }
            i++;j--;
        }
        return true;
    }
};
int main(){
    Solution sol;
    cout<<sol.isPalindrome(".,");
}
