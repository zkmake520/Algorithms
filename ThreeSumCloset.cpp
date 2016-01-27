#include<iostream>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res;
        res = INT_MAX;
        if(num.size() == 1)return num[0];
        if(num.size() == 2)return num[0]+num[1];
        sort(num.begin(),num.end());
        int beg,end;
        for(int i = 0; i < num.size();i++){
            beg = i+1;
            end = num.size()-1;
            while(beg < end){
                int sum = num[i] + num[beg] + num[end] - target;
                if(sum == 0){
                    
                    return sum+target;
                }
                if(abs(sum) < abs(res))
                    res = sum;
                if(sum < 0) beg++;
                else if(sum > 0)
                    end--;
            }
        }
        return res +target;
    }
};
int main ()
{
    
    vector<int> A;
    A.push_back(-4);
    
    A.push_back(-3);
    A.push_back(-2);
    A.push_back(-5);
    A.push_back(3);
    Solution sol;
    cout<< sol.threeSumClosest(A,-1);
    
}

