#include<vector>
#include<iostream>
#include<cstdlib>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 0)
            return 0;
        vector<int> g1(prices.size()+1, 0);
        vector<int >g2(prices.size()+1, 0);
        int min = prices[0];
        for(int i = 1; i< prices.size();i++){
            min = prices[i] < min?prices[i]:min;
            g1[i] = g1[i-1] > prices[i]-min?g1[i-1]:prices[i]-min;
        }
        int max = prices[prices.size()-1];
        for(int i = prices.size()-2; i >= 0;i--){
            max = prices[i] > max?prices[i]:max;
            g2[i] = g2[i+1] > max-prices[i]?g2[i+1]:max-prices[i];
        }
       int sum = 0;
       // cout<<g1[0]<<g2[0];
        for(int i = 0; i< prices.size();i++){
            sum = sum >g1[i]+g2[i]?sum:g1[i]+g2[i];
           // cout<<sum<<endl;
        }
        return sum;
    }
};


int main()
{
    vector<int>prices;
    prices.push_back(1);
    prices.push_back(2);
    Solution s;
   cout<< s.maxProfit(prices);
    return 0;
}
