#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int dir = 1;
        int x = 0;
        int y = 0;
        int rig = n-1;
        int lef = 0;
        
        //  cout<<1<<endl;
        vector<vector<int>> res(n,vector<int>(n,0));
        if(n==0)    return res;
        for(int i = 1; i <= n*n; i++){
            res[x][y] = i;
            if(dir == 1 && y == rig)    dir++;
            if(dir == 2 && x == rig)    dir++;
            if(dir == 3 && y == lef)    dir++,lef++;
            if(dir == 4 && x == lef)    dir = 1, rig--;
            if(dir == 1)
                y++;
            if(dir == 2)
                x++;
            if(dir == 3)
                y--;
            if(dir == 4)
                x--;
        }
        for(int i = 0; i< n;i ++){
            cout<<""<<endl;
            for(int j = 0 ; j < n;j++){
                cout<<res[i][j];
            }
        }
        return res;
    }
};
int main(){
    
    Solution sol;
    // cout<<1<<endl;
    sol.generateMatrix(4);
    
    
}