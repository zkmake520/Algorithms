#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {//˼�����Ҫ�����⣬��i-j����jͨ��������ô����֤��i-j-1�κ�һ���㶼����ͨ��j,�����ܵ�
//gas�Ǳ�cost ��ģ����Կ϶�����·����ʱ��j��ʼ����j-n-1�����ԣ��ܱ�Ȼ����һȦ����Ϊ�ܵĲ�>0,����j-n-1�����µ�gas ��Ȼ�� n-1 - jʹ��
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
