#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_set>
#include<string>;
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[32];
        int res=0;
        for(int i = 0;i < 32;i++){
                count[i] =0;
            for(int j = 0; j< n; j++){
                    if(A[j] >> i & 1){
                        count[i]++;
                    }
            }
            res |= (count[i]%3) << i;
        }
        return res;

    }

};
int main(){
    Solution sol;
    int a[7] = {1,1,1,2,2,2,3};
   // cout<<sizeof(a)/sizeof(a[0])<<endl;
    int m = sol.singleNumber(a,7);
    cout<<m<<endl;
}
