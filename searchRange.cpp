
#include <iostream>
#include <fstream>

#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
class Solution {
public:
    void Binary_search(int A[], int left, int right, int target, vector<int> &res){
        if(left > right){
            res.push_back(-1);
            res.push_back(-1);
            
            return;}
        
        int mid = (left+right)/2;
        if(A[mid] == target){
            int l ,r;
            l = r = mid;
            for(int i = mid+1; i <= right; i++){
                if(A[i] == target)
                    r = i;
                else break;
            }
            for(int i = mid-1; i >= left; i--){
                if(A[i] == target)
                    l = i;
                else break;
            }
            
            res.push_back(l);
            res.push_back(r);
            
            
            return;
        }
        else if(A[mid] < target){
            Binary_search(A, mid+1, right, target, res);
        }
        else Binary_search(A, left, mid-1, target, res);
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int>res;
        if(n == 0)  return res;
        Binary_search(A,0,n-1,target,res);
        return res;
    }
};

int main(){
    Solution sol;
    int A[6] = {5,7,7,8,8,10};
    vector<int>res =sol.searchRange(A,6,5);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i];
    
    
}
