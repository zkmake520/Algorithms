#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_set>
#include<string>;
using namespace std;
class Solution {
public:
    int length;
    int singleNumber(int A[], int n) {
        int len = n;
        n = 0;
        for(int i = 0;i < len;i++){
                n ^= A[i];
        return n;
    }
};
int main(){
    Solution sol;
    int a[5] = {1,1,2,2,3};
    cout<<sizeof(a)/sizeof(a[0])<<endl;
    int m = sol.singleNumber(a,5);
    cout<<m<<endl;
}
