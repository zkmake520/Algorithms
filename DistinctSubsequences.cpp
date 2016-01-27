#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {  //ע��ڶ���ѭ�����Ǵ�β����ʼ�ģ�
            vector<int> dp(T.size()+1,0);
            dp[0] =1;   //����0
            for(int i = 0; i< S.size(); i++){
                for(int j = T.size()-1; j >= 0;j--){
                    if(S[i] == T[j]){
                        dp[j+1] += dp[j];
                    }
                }
            }
            return dp[T.size()];
        }
};
int main(){
    string S = "b";
    string t= "b";
    Solution sol;
    cout<<sol.numDistinct(S,t);
}
