#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int >> sol;
        vector<int> AA;
        if(numRows == 0)    return sol;
        AA.push_back(1);
        sol.push_back(AA);


        for(int i = 1 ; i< numRows;i++){
            vector<int> BB;
            for(int j=0; j <= i;j++){
                int left,right;
                if(j == 0)left = 0;
                else left = sol[i-1][j-1];
                if(j == i) right =0;
                else{
                //     cout<<2<<endl;

                right =sol[i-1][j];
               //  cout<<2<<endl;
                }

                BB.push_back(left+right);
            }

            sol.push_back(BB);
        }
        return sol;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> a = sol.generate(5);
    for(int i = 0 ; i < a.size();i++){
        cout<<""<<endl;
        for(int j = 0; j < a[i].size();j++)
            cout<<a[i][j];
    }
}
