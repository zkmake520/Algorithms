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
public:
    
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        int size = num.size();
        // num.sort(num.begin(),num.end());
        sort(num.begin(),num.end());
        int i = -1;
        while(i++ < size-1){
            if(i-1>= 0 && num[i] == num[i-1])    continue;
            int beg,end;
            beg = i+1, end= size-1;
            int targetValue = -num[i];
            while(beg < end){
                if(beg -1 > i && end+1 < size){
                    if(num[beg] == num[beg-1]){
                        beg++;
                        continue;
                    }
                    if(num[end] == num[end+1]){
                        end--;
                        continue;
                    }
                }
                if(num[beg] + num[end] == targetValue) {
                    vector<int> element;
                    element.push_back(num[i]);
                    element.push_back(num[beg]);
                    element.push_back(num[end]);
                    res.push_back(element);
                    beg++;
                    end--;
                }
                else{
                    if(num[beg] + num[end] < targetValue)
                        beg++;
                    else end--;
                }
            }
        }
        return res;
        
    }
};

int main ()
{
    
    vector<int> A;
    A.push_back(-1);
    A.push_back(-1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(-2);
    A.push_back(-4);
    A.push_back(1);
    Solution sol;
    vector<vector<int>> res = sol.threeSum(A);
    for(int i = 0; i < res.size();i++){
        cout<<endl;
        for(int j = 0; j <res[i].size();j++)
            cout<<res[i][j];
    }
    
    
}