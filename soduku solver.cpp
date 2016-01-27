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
public://验证的时候每次只需要验证加入的那个就行，如果加入的是合法的，and 所有格子都填满了，那么就是合法的，记住用DFS做
    //走到这一步，那么之前的也肯定是合法的了。
    bool isValid(vector<vector<char>> &board,int r, int c){
        for(int i = 0; i < 9;i++){
            if(board[r][i] == board[r][c] && i != c)
                return false;
        }
        for(int j =0 ; j < 9; j++){
            if(board[j][c] == board[r][c] && j != r)
                return false;
        }
        int i = r/3*3;
        int j = c/3*3;
        for(int k = i; k < i+3; k++){
            for(int m = j; m < j+3; m++){
                if(board[k][m] == board[r][c] && (k!=r || m!=c))
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board){
        for(int i = 0; i  <9;i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(int k = 1; k <= 9; k++){
                        board[i][j] = '0' + k;
                        if(isValid(board, i,j) && solve(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
        solve(board);
    }
};

int main ()
{
    
    vector<vector<char>> A;
    
    Solution sol;
    sol.solveSudoku(A);
    
}

