#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 0)
            return 0;
        int max = prices[0];
        int min = prices[0];
        int gap = 0;
        int sum = 0;
        for(int i = 1; i< prices.size();i++){
            if(prices[i] > max){
                max = prices[i];
                gap = max -min>gap?max-min:gap;
            }
            if(prices[i] < max || prices[i] < min)
            {

                sum+=gap;
                gap = 0;
                min = prices[i];
                max = prices[i];
            }
        }

        return sum+gap;
    }
};
