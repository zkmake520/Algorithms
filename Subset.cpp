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
public://求集合的子集，很经典的DFS，或者说是二叉树，就是对于当前元素i，两种选择一个是加入路径（解），还有一个就是不加入解，然后分别搜索下一层树，或者下一个元素。另外很重要的一点是，只用一个path就可以得到所有的可能解。
    void dfs(vector<int> S, int index, vector<vector<int>>res, vector<int> path){
        if(index == S.size()){
            res.push_back(path);
            return;
        }
        path.push_back(S[index]);
        dfs(S,index+1,res,path);
        path.pop_back();
        dfs(S,index+1,res,path);
        
    }
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> res;
        vector<int> path;
        sort(S.begin(), S.end());
        dfs(S,0,res,path);
        return res;
    }
};

int main(){
    
    
    Solution sol;
    vector<string> A;
    A.push_back("foo");
    A.push_back("bar");
    vector<int> S;
    S.push_back(0);
    vector<vector<int>>res=sol.subsets(S);
    for(int i=0; i <res.size();i++){
        cout<<endl;
        for(int j = 0; j <res[i].size();j++)
            cout<<res[i][j];
    }
    //cout<<res[i];
    
    
}

