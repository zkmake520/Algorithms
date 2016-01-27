#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> generate(int numRows) {
        vector<int> sol;
        numRows++;
        if(numRows == 0)    return sol;
        sol.push_back(1);
        for(int i = 1 ; i< numRows;i++){
            sol[0] = 1;
            int left = 0,right = sol[0];
            for(int j=1; j < i;j++){
                left = right;
                right = sol[j];
                sol[j] = left+right;
            }
            sol.push_back(1);
        }
        return sol;
    }
};
int main(){
    Solution sol;
    vector<int> a = sol.generate(3);
    for(int i = 0 ; i < a.size();i++){
            cout<<a[i];
    }
}
