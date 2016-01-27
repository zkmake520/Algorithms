#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> res(s.size()+1, vector<vector<string>>());
        unordered_map<int,int>map;
        if(s.empty())   return res[0];
        partitionString(s,res,map);
        return res[s.size()];
    }
    void partitionString(string s,vector<vector<vector<string>>> &res,unordered_map<int,int> &map){
        if(s.empty())   return;
        if(s.size() == 1) {
            vector<string> oneSol;
            vector<vector<string>> twoSol;
            oneSol.push_back(s);
            twoSol.push_back(oneSol);
            res[s.size()] =twoSol;
        }
        if(s.size() >= 2){
		vector<vector<string>> twoSol;
        for(int i = 1; i <= s.size();i++){
            if(checkValid(s.substr(0,i)) ==  true){
                if(map.find(s.size()-i) == map.end()){
                    partitionString(s.substr(i,s.size()-i), res,map);
                    map[s.size()-i] = 1;
                }
				if(res[s.size()-i].size() == 0)
				{
					vector<string> OneSol;
					OneSol.push_back(s.substr(0,i));
					twoSol.push_back(OneSol);
				}
                for(int j = 0; j <res[s.size()-i].size();j++){
                    vector<string> oneSol;
                    oneSol.push_back(s.substr(0,i));
                    for(int k = 0; k < res[s.size()-i][j].size();k++)
                        oneSol.push_back(res[s.size()-i][j][k]);
                    twoSol.push_back(oneSol);
				/*	if(s.size() == 3)
						cout<<"a"<<endl;
					if(s.size() == 2)
						cout<<2<<endl;*/
                }
			}

        }

		res[s.size()] = twoSol;
    }
	}
    bool checkValid(string s){
        int i =0;
        int j = s.size() -1;
		if(s.size() == 1)	return true;
        for(; i <= s.size()/2-1; i++, j--){
            if(s[i] != s[j])    return false;
        }
        return true;

    }
};
int main()
{
    Solution sol;
    string s = "cacbb";
    vector<vector<string>>res = sol.partition(s);
    for(int i = 0; i < res.size();i++){
        cout<<" "<<endl;
        for(int j =0; j < res[i].size(); j++)
            cout<<res[i][j]+" ";
    }
}
