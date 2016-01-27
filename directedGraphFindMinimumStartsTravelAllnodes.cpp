#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<fstream>
#include<ostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;
int hasTryed[101];
int list[101][101];
int N;
int connectedComponents = 0;
int initialSet[101];
int traverseLog[101];
void BFS(int start){
    queue<int> que;
    que.push(start);
    initialSet[start] = 1;
    connectedComponents++;
    while(!que.empty()){
        int cur = que.front();
        if(initialSet[cur] == 1 && cur != start){
            connectedComponents--;
        }
        que.pop();
        if(traverseLog[cur] == 0){
            int i = 0;
            traverseLog[cur] = 1;
            while(list[cur][i] != 0){
                que.push(list[cur][i]);
                i++;
            }
        }
    }
}
int main(){
    int tempIn;
    cin >> N;
    for(int i = 1; i < N+1; i++){
        traverseLog[i]  = 0;
        initialSet[i] = 0;
    }
    for(int i = 1; i <= N; i++){
        int j = 0;
        cin>>tempIn;
        while(tempIn != 0){
            list[i][j++] = tempIn;
            cin>>tempIn;
        }
        list[i][j] = tempIn;
    }
    for(int i = 1; i <= N; i++){
        if(traverseLog[i] == 0)
            BFS(i);
    }
    
    cout << connectedComponents;
}
