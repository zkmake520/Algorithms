#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string rs;
        for(int i= s.length()-1; i>=0;){
            while(s[i] ==  ' ' && i >= 0) i--;
            if(i < 0)    break;
            if(!rs.empty()) rs.push_back(' ');
            string t;
            while(s[i] != ' ' && i >= 0)  {
                t.push_back(s[i--]);
            }
            reverse(t.begin(),t.end());
            rs.append(t);

        }
        s = rs;
    }
};
int main(){
        Solution sol;
        string s = "  a  ";
        sol.reverseWords(s);
        cout<< s << "bbb"<<endl;

    }
