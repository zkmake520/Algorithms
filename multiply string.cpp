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
    void addstring(string &temp, string &res,int pos){
        int ascend = 0;
        for(int i = temp.length()-1,j = pos; i >= 0; i--,j++){
            if(j < res.length()){
                int num = temp[i]-'0' + res[j]-'0';
                num += ascend;
                ascend = num/10;
                num = num %10;
                res[j] = num+'0';
            }
            else{
                int num = temp[i]-'0';
                num = num+ascend;
                ascend = num/10;
                num = num%10;
                res.push_back(num+'0');
            }
        }
        if(ascend != 0 )
            res.push_back(ascend+'0');
    }
    string multiply(string num1, string num2) {
        string res;
        int pos = 0;
        int ascend = 0;
        if(num1.length() == 1 && num1[0] == '0' || num2.length() == 1 && num2[0] =='0')  {
            res.push_back('0'); return res;
        }
        for(int i = num2.length()-1; i >= 0; i--){
            string temp;
            for(int j = num1.length()-1; j >= 0; j--){
                int num = (num2[i]-'0') *(num1[j] - '0');
                num += ascend;
                ascend = num / 10;
                num = num%10;
                temp.push_back(num+'0');
            }
            if(ascend != 0)
                temp.push_back(ascend+'0');
            reverse(temp.begin(),temp.end());
            ascend = 0;
            addstring (temp,res,pos);
            pos++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main ()
{
    string s1 = "0";
    string s2 = "12";
    string s3 = "c";
    Solution sol;
    
    cout<< sol.multiply(s1, s2);
    
    
}

