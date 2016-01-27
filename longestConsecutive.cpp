#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int max =0;
        int cur = 0;
        unordered_map<int,int> mp;
        for(int i =0; i< num.size();i++){
            mp[num[i]] = 1;
        }
        for(int i =0; i< num.size(); i++){
            if(mp[num[i]]  != 1)
                continue;
            int left = num[i]-1;
         //   cout<<left<<endl;
            mp[num[i]] = 0;
            cur = 1;
            while(mp[left] == 1){
                cur++;
                mp[left] = 0;
                left--;
            //    cout<<left<<endl;


            }
          //  cout<<cur<<endl;
            int right = num[i]+1;
         //   cout<<right<<endl;
            while(mp[right] == 1)
            {
                mp[right] = 0;

                cur++;
                right++;
             //   cout<<right<<endl;
            }
            max = cur>max?cur:max;
        }
        return max;
    }
};
int main()
{
    Solution sol;
    vector<int> num;
     num.push_back(122);
    num.push_back(1);
     num.push_back(2); num.push_back(444);
      num.push_back(3);
       num.push_back(4);

    cout<<sol.longestConsecutive(num);

}
