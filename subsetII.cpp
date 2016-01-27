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
    void DFS(vector<vector<int>> &res, vector<int> &path, int index, vector<int> &S, int status, int number){
        if(index == S.size()){
            res.push_back(path);
            return;
        }
        if(S[index] != number ||(S[index] == number && status == 1)){ // in duplicate
            // lastNumber is yes, this iteration can use both 1 and 0
            path.push_back(S[index]);
            DFS(res,path,index+1,S,1,S[index]);
            path.pop_back();
            DFS(res,path,index+1,S,0,S[index]);
        }
        else{
            DFS(res,path,index+1,S,0,S[index]);
        }
        
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> path;
        vector<vector<int>> res;
        if(S.empty())   return  res;
        sort(S.begin(), S.end());
        int lastStatus = -1;
        int number = INT_MAX;
        DFS(res, path,0,S,lastStatus,number);
        return res;
        
    }
};
int main(){
    Solution sol;
    vector<int> S;
    S.push_back(1);
    S.push_back(2);
    S.push_back(2);
    vector<vector<int>>res = sol.subsetsWithDup(S);
    for(int i = 0; i< res.size();i++){
        cout<<endl;
        row = i;
        for(int j =0; j < res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
    }
    
}

