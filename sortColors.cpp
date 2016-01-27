#include<iostream>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {//不要想着把0加入到0后面，可以将从最前面开始往后放，2从最后面往前放。笨死了
public:
    //这题有很多的细节可以扣，譬如当把2交换到后面取得时候，交换过来的值，要重新进行在此运算，不能直接忽略，
    void swap(int A[],int i ,int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    void sortColors(int A[], int n) {
        int zero,two;
        zero = 0;
        two = n-1;
        for(int i = 0 ; i < n;){
            switch(A[i]){
                case 0:
                    if(i <= zero){
                        i++;
                        break;
                    }
                    swap(A,i,zero);
                    zero++;
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    if(i > two){
                        i++;
                        break;
                    }
                    swap(A,i,two);
                    two--;
                    break;
            }
        }
    }
};
int main(){
    
    
    Solution sol;
    
    int A[3] ={1,2,0,0,0,2};
    
    sol.sortColors(A,3);
    for(int i = 0; i <3;i++)
        cout<<A[i];
    
}

