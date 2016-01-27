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
public: //对于每块板，求以他为高度时候的，左右界，用单调栈实现
    int largestRectangleArea(vector<int> &height) {
        int res = INT_MIN;
        vector<int> left;
        stack<int> sta;
        int i = 0;
        if(height.size() == 0)  return 0;
        left.push_back(0);
        sta.push(0);
        while(i++ < height.size()-1){
            if(height[sta.top()] <= height[i]){
                sta.push(i);
                left.push_back(sta.top());
            }
            else{
                //if(height[i] == 2)
                //  cout<<2<<endl;
                int index;
                while(!sta.empty() && height[sta.top()] > height[i]){
                    index = sta.top();
                    sta.pop();
                    res = (res > height[index]*(i-left[index]))?res:height[index]*(i-left[index]);
                    
                }
                if(sta.empty()) left.push_back(0);
                else left.push_back(sta.top()+1);
                sta.push(i);
            }
        }
        while(!sta.empty()){
            int index = sta.top();
            sta.pop();
            res = (res > height[index]*(i-left[index]))?res:height[index]*(i-left[index]);
        }return res;
    }
    
};
int main ()
{
    
    vector<int> A;
    A.push_back(2);
    A.push_back(1);
    A.push_back(5);
    A.push_back(6);
    A.push_back(4);
    A.push_back(2);
    A.push_back(3);
    A.push_back(3);A.push_back(3);
    Solution sol;
    cout<< sol.largestRectangleArea(A);
    
}

 s