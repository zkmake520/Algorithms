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
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row,col;
        row = col = 0;
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        for(int i = 0; i < matrix.size();i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    if(i == 0)  row = 1;
                    if(j == 0)  col = 1;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[0][j] == 0|| matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(row == 1)    for(int i = 0; i < matrix[0].size(); i++)   matrix[0][i] = 0;
        if(col == 1)    for(int i = 0; i < matrix.size(); i++)   matrix[i][0] = 0;
        return;
    }
};
int main ()
{
    vector<vector<int>> A;
    
    Solution sol;
    cout<<2;
    sol.setZeroes(A);
    
}

