#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size = triangle.size();
        vector<int> min(size+1,0);
        while(size--){
            for(int i = 0 ; i <= size; i++){

                min[i] = triangle[size][i] + (min[i] < min[i+1]?min[i]:min[i+1]);
               // cout<<min[i];
            }
        }
        return min[0];

    }

};
int main(){
    Solution sol;
    vector<vector<int>> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    vector<int> e;
    b.push_back(-5);
    c.push_back(-2);
    c.push_back(-3);
    d.push_back(-4);
    d.push_back(-4);
    d.push_back(-4);
    e.push_back(7);
    e.push_back(7);
    e.push_back(8);
    e.push_back(8);
    a.push_back(b);
    a.push_back(c);
    a.push_back(d);
    a.push_back(e);
  //  cout<<b[0];
    cout<<sol.minimumTotal(a);

}
