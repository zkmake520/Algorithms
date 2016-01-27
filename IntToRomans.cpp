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
#define One 'I';
#define Five 'V';
#define Ten 'X';
#define Fifth 'L';
#define Hundred 'C';
#define Fhundred 'D';
#define Thousand 'M';
class Solution {
public://此处可能性不多，可以直接全部列举出来各种的可能性,然后从高位到地位，直接根据数字得出字符串
    
    string intToRoman(int num) {
        char *Huns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        char *Tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        char *Digit[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string res;
        while(num >= 1000){
            num -= 1000;
            res += "M";
        }
        res += Huns[num/100];
        num = num-num/100*100;
        res += Tens[num/10];
        num = num- num/10*10;
        res += Digit[num];
        return res;
    }
};
int main(){
    
    
    Solution sol;
    
    cout<<sol.intToRoman(2143));
    
}

