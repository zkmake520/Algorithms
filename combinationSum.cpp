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
    void DFS(vector<vector<int>> &res, vector<int> &candidates, int index, int target,vector<int> &path, int sum){
        if(sum == target){
            res.push_back(path);
            return;
        }
        if(sum > target || index >= candidates.size())
            return;
        int extra = 1;
        while(sum+extra*candidates[index] <= target){
            path.push_back(candidates[index]);
            DFS(res,candidates,index+1,target,path,sum+extra*candidates[index]);
            extra++;
        }
        extra--;
        for(int i = 0; i < extra; i++)
            path.pop_back();
        if(extra == 0)
            return;
        else
            DFS(res,candidates,index+1,target,path,sum);
        return;
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        DFS(res, candidates,0, target,path,sum);
        return res;
    }
    
};
int main(){
    Solution sol;
    vector<int> candidates ={2,3,6,7};
    vector<vector<int>> res =sol.combinationSum(candidates, 13);
    for(int i = 0; i < res.size();i++){
        cout<<endl;
        for(int j = 0; j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
    }
}

