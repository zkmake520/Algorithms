#include<iostream>
#include<unordered_map>
#include<cstdlib>
#include<vector>

using namespace std;

 struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> graphMap;
        UndirectedGraphNode *cur = node;

         cloneNode(graphMap,cur);
         cur = graphMap[cur->label];
         return cur;
    }
    UndirectedGraphNode * cloneNode(unordered_map<int, UndirectedGraphNode *> &graphMap,UndirectedGraphNode *cur){
        if(cur == NULL) return NULL;
        if(graphMap.find(cur->label) != graphMap.end())
            return graphMap[cur->label];
        UndirectedGraphNode * newNode = new UndirectedGraphNode(cur->label);
        graphMap[cur->label] = newNode;
        for(int i = 0; i < cur->neighbors.size();i++){
            newNode = cloneNode(graphMap,cur->neighbors[i]);
            graphMap[cur->label]->neighbors.push_back(newNode);
        }
        return graphMap[cur->label];
    }
};
int main(){
    Solution sol;
    UndirectedGraphNode *n1 = new UndirectedGraphNode(1);
    UndirectedGraphNode *n2 = new UndirectedGraphNode(2);
    UndirectedGraphNode *n3 = new UndirectedGraphNode(3);

    n1->neighbors.push_back(n1);
    n1->neighbors.push_back(n1);
    n1->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n3);
    UndirectedGraphNode * cur = sol.cloneGraph(n1);

}
