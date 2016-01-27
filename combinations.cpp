#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void combination(int s,int e,int k,vector<vector<int>> &res,vector<int> &path){
        int begin = s;
        if (k == 0){
            res.push_back(path);
            return;}
        for(begin = s; e-begin>=k-1;begin++)
        {
            path.push_back(begin);
            combination(begin+1,e,k-1,res,path);
            path.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res;
        vector<int>path;
        combination(1,n,k,res,path);
        return res;
    }
};

int main(){
	Solution sol;
	vector<vector<int>> res =sol.combine(4,2);
	for(int i = 0;i <res.size();i++){
		cout<<endl;
		for(int j = 0; j < res[i].size();j++){
			cout<<res[i][j]<<",";
		}
	}
}