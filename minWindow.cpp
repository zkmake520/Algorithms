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
using namespace std;//双指针，p1,p2,与传统的字符串比较不同，因为这里不用考虑顺序，所以我们只需要记录p1，p2区域内相应字符的数量即可，一旦满足要求，p1即可以向p2逼近，如果当前字符数量大于所要求，即可以去掉该字符。
//还有一点为了加快速度，可以不用map, 因为一个char型表示的范围是0-255，所以用int [256]即能表示所有的字符，无用的字符数量为1，必然大于Tc串中该字符（没有）为0的数量，所以必然可以直接跳过。
class Solution {
public:
    string minWindow(string S, string T) {
        int Tstr[256];
        memset(Tstr,0,sizeof(Tstr));
        int Sstr[256];
        memset(Sstr,0,sizeof(Sstr));
        int p1,p2;
        int num = T.length();
        int min,max;
        min = -1;
        int minlength = INT_MAX;
        for(int i = 0; i< T.length(); i++)
            Tstr[T[i]]++;
        for(p2 = p1 = 0; p2 < S.length(); p2++){
            if(Sstr[S[p2]] < Tstr[S[p2]]){
                num--;
            }
            Sstr[S[p2]]++;
            if(num == 0){
                while(Sstr[S[p1]] > Tstr[S[p1]]){
                    Sstr[S[p1]]--;
                    p1++;
                }
                if(minlength > p2-p1+1){
                    min = p1;
                    max = p2;
                    minlength = p2-p1+1;
                }
            }
        }
        if(min == -1)   return "";
        return S.substr(min,max-min+1);
    }
};
int main ()
{
    
    Solution sol;
    string A = "A";
    string B = "AA";
    
    cout<< sol.minWindow(A, B);
    
    
}

