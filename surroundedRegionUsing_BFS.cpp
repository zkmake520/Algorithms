#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    struct point{
        int x;
        int y;
        point(int a,int b){x= a;y =b;}
    };
    void solve(vector<vector<char>> &board) {//这题从外围开始考虑，如果外围一圈有0，那么从这个0出发的连续的0,也就是说从这个点出发进行bfs得到的都不能成为x
        if(board.size() == 0) return;
        if(board[0].size() == 0) return;
        vector<point> vec;
       int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i = 0; i < board.size(); i++){
            if(board[i][0] =='O')   vec.push_back(point(i,0));
            if(board[i][board[0].size()-1] == 'O')  vec.push_back(point(i,board[0].size()-1));
        }
        for(int i = 1; i < board[0].size()-1; i++){
            if(board[0][i] =='O')   vec.push_back(point(0,i));
            if(board[board.size()-1][i] == 'O') {
                vec.push_back(point(board.size()-1,i));
            }

        }
        while(!vec.empty()){
            point p = vec.back();
            vec.pop_back();
            board[p.x][p.y] ='D';
          //  cout<<board[3][1]<<endl;
            for(int i =0; i< 4;i++){
                int x = p.x + dir[i][0];
                int y = p.y + dir[i][1];
                if(x < 0||x > board.size()-1||y<0||y> board[0].size()-1 || board[x][y] != 'O')  continue;
                vec.push_back(point(x,y));
            }
        }
     //   cout<<board[3][1]<<endl;
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j< board[0].size(); j++){
                if(board[i][j] == 'X') continue;
             //   if(board[i][j] == 'D') cout<<11;
                board[i][j] = board[i][j] == 'O'?'X':'O';
            }
        }
    }


};
int main()
{
    vector<vector<char>> board(4,vector<char>(4,'X'));
    board[1][1] = 'O';
    board[1][2] = 'O';
    board[2][2] = 'O';
    board[3][1] = 'O';
    Solution sol;
    sol.solve(board);
      for(int i = 0; i<board.size(); i++){
            cout<<""<<endl;
            for(int j = 0; j< board[0].size(); j++){
              cout<<board[i][j];
            }
        }

}
