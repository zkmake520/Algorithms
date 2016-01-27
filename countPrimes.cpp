#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> table(n,true); 
        for(long i = 2; i < n; i++){
        	for(long j = i; j < n; j ++){
        		if(j * i < n){
        			cout<<j<<" "<<i<<endl;
        			table[j*i] = false;
        		}
        		else{
        			break;
        		}
        	}
        }
        int count = 0;
        for(int i = 1; i < n; i++){
        	if(table[i] == true){
        		count ++;
        	}
        }
        return count;
    }
};
int main(){
	Solution sol;
	cout<< sol.countPrimes(499979);
}