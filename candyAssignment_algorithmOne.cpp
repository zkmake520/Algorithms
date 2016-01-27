#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {  //这边特别要注意相等的情况
        int *count =new int[ratings.size()];
        count[0] = 1;
        for(int i = 1;i < ratings.size();i++){
            count[i] = ratings[i] > ratings[i-1] ? count[i-1]+1:1;
       //     cout<<count[i]<<endl;
        }
        for(int i = ratings.size()-2; i>=0;i--){
            int tmp = ratings[i]> ratings[i+1]? count[i+1]+1:1;
            count[i]= tmp > count[i]? tmp:count[i];
         //   cout<<count[i]<<endl;
        }
        int sum =0;
        for(int i =0; i< ratings.size();i++)    sum+= count[i];
        return sum;
    }
};
int main(){
    vector<int> rating;
    rating.push_back(1);
    rating.push_back(2);
    rating.push_back(4);
    rating.push_back(3);
    rating.push_back(2);
    rating.push_back(2);
    rating.push_back(1);
    Solution sol;
    cout<<sol.candy(rating);



}
