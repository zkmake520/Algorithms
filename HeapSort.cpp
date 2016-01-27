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
class Solution {
public:
    void swap(int A[], int i, int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    void MaxHeapify(int A[], int i, int heapSize){
        int left = i*2;
        int right = i*2+1;
        int max;
        int pos = -1;
        if(left > heapSize && right > heapSize) return;
        if(left > heapSize){
            max = A[right-1];
            pos = 1;
        }
        else if(right > heapSize){
            max = A[left-1];
            pos = 0;
        }
        else{
            if(A[left-1] > A[right-1]){
                max = A[left-1];
                pos = 0;
            }
            else{
                max = A[right-1];
                pos = 1;
            }
        }
        if(A[i-1] < max){
            int temp = A[i-1];
            A[i-1] = pos == 1?A[right-1]:A[left-1];
            if(pos == 1)
                A[right-1] =temp;
            else A[left-1] =temp;
        }
        if(pos == 0)
            MaxHeapify(A, left, heapSize);
        else MaxHeapify(A, right, heapSize);
    }
    
    void BuildMaxHeap(int A[],int heapSize){
        for(int i = heapSize/2; i >= 1; i--)
            MaxHeapify(A,i,heapSize);
    }
    void HeapSort(int A[], int n){
        int heapSize = n;
        BuildMaxHeap(A,heapSize);
        swap(A,0,heapSize-1);
        heapSize--;
        while(heapSize > 1){
            
            MaxHeapify(A,1,heapSize);
            swap(A,0,heapSize-1);
            heapSize--;
        }
        return;
    }
};
int main(){
    
    
    Solution sol;
    
    
    int A[8] ={1,2,3,8,5,4,6,7};
    sol.HeapSort(A,8);
    for(int i =0 ; i<8;i++)
        cout<<A[i];
    
}

