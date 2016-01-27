#include<iostream>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<vector>
#include<stdio.h>
using namespace std;
class Solution {
public://注意细节处理，当有数字大于2时，以及只剩最后一个Ip段时，以及有非法的字符时候，应该将字符给去掉，还有就是当IP某段的数字大于2255时
    vector<string>  restore(vector<string> &res, int num,string s){
        int i,j,k;
        i = 0;
        if(num == 1){
            if(s[0] == '0' && s.size() > 1) return res;
            if(s.size() == 3 && atoi(s.c_str()) > 255)   return res;
            res.push_back(s);
            return res;
        }
        while(i++ < 3){
            if(s.size() - i < num-1)    break;
            if(s.size() - i > (num-1)*3) continue;
            if(i == 3 && atoi(s.substr(0,i).c_str()) >255) break;
            string tmp = s.substr(0,i);
            tmp.push_back('.');
            vector<string> temp;
            restore(temp,num-1,s.substr(i,s.size()-i));
            for(j = 0; j < temp.size(); j++){
                res.push_back(tmp+temp[j]);
            }
            if(s[0] == '0')
                return res;
        }
        return res;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size() < 4 || s.size() > 12)    return res;
        string legalS;
        for(int i = 0 ; i < s.size(); i++)
            if('0'<= s[i] <='9') legalS.push_back(s[i]);
        return restore(res,4,s);
    }
};
int main ()
{
    
    string b = "000256""";
    Solution sol;
    vector<string> res = sol.restoreIpAddresses(b);
    for(int i = 0; i< res.size();i++){
        cout<<res[i]<<endl;
    }
}