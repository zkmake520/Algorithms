#include<iostream>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<unordered_map>
using namespace std;
class Solution {
public://FindtheHighestOne,then left to this one, right to this one,two times scanning.
    //update the max one onthe path
    //then the area is the sum of max - A[i];
    int trap(int A[], int n) {
        int maxHeight = INT_MIN;
        int maxIndex = -1;
        for(int i = 0; i < n;i++){
            if(A[i] > maxHeight){
                maxHeight = A[i];
                maxIndex = i;
            }
        }
        int res = 0;
        int max = 0;
        for(int i = 0; i < maxIndex; i++){
            if(A[i] < max)
                res+=max-A[i];
            else max = A[i];
        }
        max = 0;
        for(int i = n-1; i > maxIndex;i--){
            if(A[i] < max)
                res+=max-A[i];
            else max = A[i];
        }
        return res;
    }
};
int main ()
{
    
    int A[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    cout<< sol.trap(A,12);
    
}

