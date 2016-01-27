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
private: int row[1000]; //存放每一行的位置
private: int col[1000]; //表示每一列是否可行
public: // 这边和suduko不同的是不用返回true，因为要找所有的，所以无论如何都要找所有可能性的，还有就是对row，col的恢复处理方式。
    void solve(vector<vector<string>> &res, int b,int n){
        if(b == n){
            vector<string> ele;
            for(int i = 0; i < n;i++){
                string temp(n,'.');
                temp[row[i]] = 'Q';
                ele.push_back(temp);
            }
            res.push_back(ele);
        }
        else{
            for(int i = 0; i < n; i++){
                if(col[i] == 0){
                    int j;
                    for(j = 0; j < b; j++)
                        if(abs(j-b) == abs(i-row[j]))   break;
                    if(j == b){
                        row[b] = i;
                        col[i] = 1;
                        solve(res,b+1,n);
                        row[b] = -1;
                        col[i] = 0;
                    }
                }
            }}
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> res;
        for(int i = 0 ; i< 1000;i++){
            row[i] = -1;
            col[i] = 0;
        }
        solve(res,0,n);
        return res;
    }
};
int main ()
{
    
    Solution sol;
    
    vector<vector<string>> res = sol.solveNQueens(4);
    for(int i = 0; i<res.size(); i++){
        cout<<endl;
        for(int j = 0; j < 4; j++){
            cout<<res[i][j];
        }
    }
}

