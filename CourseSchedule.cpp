#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<utility>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        //using topological ordering .    finding all those nodes whose incoming degree ==0
        vector<vector<int>> graph (numCourses,vector<int>(0));
        vector<int> in(numCourses,0);
        for(int i = 0; i <prerequisites.size(); i++){
            pair<int,int> p;
            p = prerequisites[i];
            graph[p.second].push_back(p.first);
            in[p.first]++;
        }
        queue<int> que;
        for(int i = 0; i< numCourses; i++){
            if(in[i] == 0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(int i = 0; i < graph[cur].size(); i ++){
                in[graph[cur][i]]--;
                if(in[graph[cur][i]] == 0){
                    que.push(graph[cur][i]);
                } 
            }
        }
        for(int i = 0 ; i < numCourses;i++){
            if(in[i] != 0){
                return false;
            }
        }
        return true;
    }
};
int main(){
	Solution sol;
	pair<int,int> p1 (2,0);
	pair<int,int> p2 (2,1);
	std::vector<pair<int,int> >  v;
	v.push_back(p1);
	v.push_back(p2);
	cout<<sol.canFinish(3,v);
}