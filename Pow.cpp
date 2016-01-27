#include<iostream>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
using namespace std;


class Solution {
public: //计算机种都用的是补码，所以可以表示-128，同时0，也是一样的，原码只是为了换成补码
    double pow(double x, int n) {
        double res = 1.0;
        double temp = 1;
        if(n == 0)
            return 1.0;
        if(n > 0){
            for(; n > 0; temp*=temp,n >> 1){
                if( n & 1){
                    res *=temp;
                }
            }
            return res;
        }
        if(n < 0){
            if(n == INT32_MIN)
                return 1.0/pow(x,-INT32_MAX)*x;
            
            else
                return 1.0/pow(x,-n);
        }
        return 0;
    }
};

int main ()
{
    cout<<pow(8.88023,3);
}