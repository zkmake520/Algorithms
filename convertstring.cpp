//
//  convertstring.cpp
//  
//
//  Created by zkwangchao on 14-4-9.
//
//

//
//  lengthOfLongestSubString.cpp
//
//
//  Created by zkwangchao on 14-4-8.
//
//

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        string ans;
        if(nRows == 1)  return s;
        int base = 2*nRows -2;
        int oddOrRight;
        for(int i = 0; i < nRows; i++){
            int target = i;
            oddOrRight = 0;
            while(target <= s.size()-1){
                ans.push_back(s[target]);
                //   cout<<target<<s[target]<<endl;
                int tmp = oddOrRight == 0 ?i:nRows-i-1;
                if(i == 0)
                    target += base;
                else if(i == nRows-1)
                    target +=base;
                else
                    target += base-2*tmp;
                oddOrRight = 1 - oddOrRight;
            }
        }
        return ans;
    }
};
int main(){
    
    Solution sol;
    string ans = sol.convert("PAYPALISHIRING",3);
    cout<<ans;
    
}