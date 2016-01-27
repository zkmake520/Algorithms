#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<ostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<queue>
#include<unordered_map>
int beg, des;
using namespace std;
int row;
class Solution {
public:
    bool DFS(vector<vector<char>> &board, string &word, int index, int row, int col,vector<vector<bool>> &path){
        if(index == word.size())
            return true;
        
        if(board[row][col] == word[index]){
            path[row][col] = true;
            if(row-1>=0 && path[row-1][col] !=true)
                if(DFS(board,word,index+1,row-1,col,path))
                    return true;
            if(row+1<board.size() && path[row+1][col] !=true)
                if(DFS(board,word,index+1,row+1,col,path))
                    return true;
            if(col-1>=0 && path[row][col-1] !=true)
                if(DFS(board,word,index+1,row,col-1,path))
                    return true;
            if(col+1<board[0].size() && path[row][col+1] !=true)
                
                if(DFS(board,word,index+1,row,col+1,path))
                    return true;
            path[row][col] = false;
        }
        
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<bool>> path(board.size(), vector<bool>(board[0].size()));
        
        for(int i =0; i < board.size();i++){
            for(int j =0;j < board[0].size();j++){
                if(DFS(board,word,0,i,j,path) == true)
                    return true;
            }
        }
        return false;
    }
};
int main(){
    Solution sol;
    vector<vector<char>> s ={{'a','a'}};
    bool res =sol.exist(s, "aaa");
    cout<<res<<endl;
    
}

