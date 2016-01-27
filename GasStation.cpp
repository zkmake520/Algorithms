#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {//思想很重要，这题，当i-j，在j通不过，那么可以证明i-j-1任何一个点都不能通过j,由于总的
//gas是比cost 多的，所以肯定有线路，此时从j开始，如j-n-1都可以，能必然能绕一圈，因为总的差>0,所以j-n-1后，留下的gas 必然够 n-1 - j使用
        int sum=0;
        int tota=0;
        int index = 0;
        for(int i =0; i< gas.size();i++)
        {
            sum+= gas[i] - cost[i];
            tota +=gas[i] -cost[i];
            if(sum <0){
                index = i+1;
                sum  = 0;
            }
        }
        if(tota < 0)   return -1;
        else return index;
    }
};
int main(){

    vector<int > gas,cost;
    gas.push_back(5);



    cost.push_back(4);

    Solution sol;
    cout<<sol.canCompleteCircuit(gas,cost);
}
