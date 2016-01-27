#include<iostream>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<vector>
using namespace std;

class Solution {
public://注意几点，一个是当排序是最后一个时，会循环到第一个
    void reserve(vector<int> &num, int i, int j){
        while(i < j){
            int tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
            i++,j--;
        }
    }
    void nextPermutation(vector<int> &num) {
        int i = num.size();
        int len = i;
        while(i-- >0){
            if(i == 0)  break;
            if(num[i-1] < num[i]){
                for(int j = len-1; j >= i; j--){
                    if(num[j] > num[i-1]){
                        int tmp = num[i-1];
                        num[i-1] = num[j];
                        num[j] = tmp;
                        break;
                    }
                }
                reserve(num,i,len-1);
                return;
            }
            
        }
        if(i == 0)  reserve(num,0, len-1);
        return;
    }
};
int main ()
{
    
    vector<int> b;
    b.push_back(2);
    b.push_back(3);
    b.push_back(5);b.push_back(4);
    b.push_back(1);
    
    Solution sol;
    sol.nextPermutation(b);
    cout<<b[0];
    cout<<b[1];
    cout<<b[2];
    cout<<b[3];
    cout<<b[4];
}