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
struct Node{
    int node;
    int cost;
    string name;
    int parent;
    Node (int a,int b, string c,int d): node(a),cost(b),name(c),parent(d) {}
};

bool comparision(const Node &a,const Node &b){
    return a.name < b.name;
}

struct cmp{
    bool operator()(const Node &a,const Node &b){
        if(a.cost > b.cost)
            return a.cost  > b.cost;
        else {
            return a.name > b.name;
        }
    }
};
bool DFS(vector<Node> &nodes,vector<int> &discovered,vector<vector<int>> &edgeMap,int nodeNumber,
         vector<string> &log){
    stack<Node> sta;
    int i;
    nodes[beg].cost = 0;
    sta.push(nodes[beg]);
    discovered[beg] = 1;
    vector<Node> array;
    
    while(!sta.empty()){
        array.clear();
        Node temp = sta.top();
        sta.pop();
        log.push_back(temp.name);
        discovered[temp.node] = 1;
        if(temp.node == des)
            return true;
        for(i =0; i < nodeNumber;i++){
            if(edgeMap[temp.node][i] != 0 & discovered[i] == 0){
                nodes[i].cost = temp.cost+1;
                nodes[i].parent = temp.node;
                array.push_back(nodes[i]);
            }
        }
        sort(array.begin(),array.end(),comparision);
        for(i = array.size()-1; i >=0; i--)
            sta.push(array[i]);
    }
    return  false;
}
bool BFS(vector<Node> &nodes,vector<int> &discovered,vector<vector<int>> &edgeMap,int nodeNumber,
         vector<string> &log){
    queue<Node> que;
    nodes[beg].cost = 0;
    que.push(nodes[beg]);
    discovered[beg] = 1;
    vector<Node> array;
    while(!que.empty()){
        Node temp = que.front();
        que.pop();
        log.push_back(temp.name);
        
        if(temp.node == des)
            return true;
        for(int i =0; i < nodeNumber;i++){
            if(edgeMap[temp.node][i] != 0 & discovered[i] == 0){
                nodes[i].cost = temp.cost+1;
                nodes[i].parent = temp.node;
                discovered[i] = 1;
                array.push_back(nodes[i]);
            }
        }
        sort(array.begin(),array.end(),comparision);
        for(int i = 0; i < array.size();i++)
            que.push(array[i]);
        array.clear();
    }
    return false;
    
}
bool UCS(vector<Node> &nodes,vector<int> &discovered,vector<int> &openList,vector<vector<int>> &edgeMap,int nodeNumber,vector<string> &log){
    priority_queue<Node,vector<Node>, cmp> que;
    nodes[beg].cost = 0;
    que.push(nodes[beg]);
    openList[beg] = 1;
    while(!que.empty()){
        Node temp = que.top();
        discovered[temp.node] = 1;
        que.pop();
        log.push_back(temp.name);
        if(temp.node == des)    return true;
        for(int i =0;i < nodeNumber;i++){
            if(edgeMap[temp.node][i] != 0 & discovered[i] == 0){
                if(openList[i] == 0 ||temp.cost+edgeMap[temp.node][i] < nodes[i].cost){
                    nodes[i].parent = temp.node;
                    nodes[i].cost = temp.cost+edgeMap[temp.node][i];
                    que.push(nodes[i]);
                    openList[i] = 1;
                }
                
            }
        }
    }
    return false;
}
int main(){
    fstream read;
    read.open("/Users/zkwangchao/Desktop/leetcode/test2/input.txt");
    ofstream out("/Users/zkwangchao/Desktop/leetcode/test2/output.txt");
    vector<int> path;
    vector<Node> nodes;
    string source,destination ;
    string buf;
    int method,nodeNumber;
    int i,j;
    string getChar;
    //input data
    read>> method;
    read>>source;
    read>>destination;
    read>>nodeNumber;
    
    vector<vector<int>>  edgeMap(nodeNumber,vector<int>(nodeNumber));
    vector<string> log;
    
    vector<int> discovered(nodeNumber);
    vector<int> openList(nodeNumber);
    
    for(i=0; i < nodeNumber;i++){   discovered[i] = 0;openList[i] =0;}
    for(i=0; i < nodeNumber;i++){
        read>>buf;
        if(buf == source)
            beg = i;
        else if(buf == destination)
            des = i;
        nodes.push_back(Node(i,INT_MAX,buf,-1));
    }
    for(i=0; i < nodeNumber;i++){
        for(j = 0;j < nodeNumber; j++){
            read>>edgeMap[i][j];
        }
    }
    //BFS，DFS,UCS
    bool result = false;
    switch(method){
        case 1:
            result = BFS(nodes,discovered,edgeMap,nodeNumber,log);
            break;
        case 2:
            result = DFS(nodes,discovered,edgeMap,nodeNumber,log);
            
            break;
        case 3:
            result = UCS(nodes,discovered,openList,edgeMap, nodeNumber,log);
            break;
            
    }
    
    for(i = 0; i < log.size();i++){
        if(i == log.size()-1){
            out<<log[i]<<"\n";
        }
        else out<<log[i]<<'-';
    }
    if(result == true){
        int costSum = 0;
        i = des;
        vector<string> path;
        while(nodes[i].node != beg){
            path.push_back(nodes[i].name);
            costSum += edgeMap[i][nodes[i].parent];
            i = nodes[i].parent;
        }
        path.push_back(nodes[i].name);
        reverse(path.begin(), path.end());
        for(i = 0; i < path.size();i++){
            if(i == path.size()-1){
                out<<path[i]<<"\n";
            }
            else out<<path[i]<<"-";
        }
        out<<costSum;
    }
    else
        out<<"NoPathAvailable\n";
    read.close();
    out.close();
    
}

