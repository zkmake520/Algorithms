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
public://非常非常棒的想法，包括对两数是否是正负数，已经对用减法实现除法。
    //从先减一个divisor开始，此时+1，然后减divisor的两倍，加2,一直下去，
    //有点要注意的是当divisor变得很大的时候，此时，也许 dividend不能一次性减掉，所以不能一次性加1<<i；
    //此时，则需要通过循环，将剩余的a，重新开始减
    int divide(int dividend, int divisor) {
        long long a = abs((long long ) dividend);
        long long b = abs((long long )divisor);
        long long res = 0;
        while(a >= b){
            long long c = b;
            for(int i = 0; a >=c; i++ , c <<=1){
                a -= c;
                res += 1<<i;
            }
        }
        return ((dividend ^ divisor) >>31)?-res:res;
    }
};
int main(){
    
    
    Solution sol;
    
    cout<<sol.divide(5, 2);
    
}

