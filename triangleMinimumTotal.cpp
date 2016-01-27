#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    struct Node{
        int path;
        int x;
        int y;
        Node(int a, int b,int c): x(a),y(b),path(c){}
    };
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<Node> vec;
        int minimum = INT_MAX;
        if(triangle.size() == 0)    return 0;
       // cout<<2;
       // cout<<triangle[0][0];
        vec.push_back(Node(0,0,triangle[0][0]));
      //  cout<<2;
        while(!vec.empty()){
            Node node = vec.back();

            vec.pop_back();
            int x =node.x;
            int y = node.y;
          //  cout<<node.path;
            if(x == triangle.size()-1){
                if(node.path < minimum)
                    minimum = node.path;
                    continue;

            }
            if(y-1 > 0){
                if(triangle[x][y] < triangle[x][y-1]){
                    vec.push_back(Node(x+1,y,node.path+triangle[x+1][y]));
                }
            }
            else    vec.push_back(Node(x+1,y,node.path+triangle[x+1][y]));
            if(y+1 < x){
                if(triangle[x][y] <= triangle[x][y+1]){
                    vec.push_back(Node(x+1,y+1,node.path+triangle[x+1][y+1]));
                }
            }
            else    vec.push_back(Node(x+1,y+1,node.path+triangle[x+1][y+1]));

        }
        return minimum;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    vector<int> e;
    b.push_back(-3);
    c.push_back(-9);
    c.push_back(7);
    d.push_back(3);
    d.push_back(2);
    d.push_back(-4);
    e.push_back(4);
    e.push_back(6);
    e.push_back(-1);
    e.push_back(9);
    a.push_back(b);
    a.push_back(c);
    a.push_back(d);
    a.push_back(e);
  //  cout<<b[0];
    cout<<sol.minimumTotal(a);

}

