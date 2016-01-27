#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

        vector<vector<string>> sol;
        vector<string>oneSol;
        if(start == end){
            oneSol.push_back(start);
            sol.push_back(oneSol);
            return sol;
        }
        queue<string> vec;
      //  vector<int> len;
        unordered_map<string,int>mp;
        unordered_map<string,vector<string>>mpStr;
        int shortLength = INT_MAX;
		int changed = 0;
        vec.push(start);
        mp[start] = 1;
        int step = 0;

        while(!vec.empty()){  //这边为了避免tle。一个非常好的做法是把当前的单词的每一个字母进行相应替换，这样就是26*wordLength。而不是把字典中的每个都进行查找一边
          //  cout<<2<<endl;
            string cur = vec.front();
            if(mp[cur] >= shortLength)
                break;
            vec.pop();
            for(int i = 0;i < cur.size(); i++){
                string tmp = cur;
					//if(sign == 1)	break;
                for(char j = 'a'; j!='z'+1; j++){
                    tmp[i] = j;
                    if(tmp == end)   {
                        shortLength = mp[cur]+1;
                        mpStr[end].push_back(cur);
                       //cout<<cur<<endl;

                    }
                    else{
                        if(dict.find(tmp) != dict.end() && mp.find(tmp) != mp.end()){ //从别的路径也可以到，如果step一样，则加入
                            if(mp[cur]+1 == mp[tmp])
                                mpStr[tmp].push_back(cur);
                              //   cout<<cur<<endl;

                        }
                        if(dict.find(tmp) != dict.end() && mp.find(tmp) == mp.end()){
                            mp[tmp] = mp[cur]+1;
                            mpStr[tmp].push_back(cur);
                            vec.push(tmp);
                        }
                   }
                }
            }
        }
        if(shortLength == INT_MAX)   return sol;
       /* for(int i = 0; i< mpStr[end].size();i++)
            cout<<mpStr[end][i]<<endl;*/
        getAllString(sol,start,end,mpStr);
        return sol;
    }
    void getAllString(vector<vector<string>> &sol, string start, string end,unordered_map<string,vector<string>> &mpStr){
        vector<vector<string>> ans;
        vector<string> tmp;
        if(start == end){
            tmp.push_back(start);
            sol.push_back(tmp);
            return;
        }
        for(int i = 0; i< mpStr[end].size();i++){
            getAllString(ans,start,mpStr[end][i],mpStr);
        }
        for(int i = 0; i<ans.size(); i++){
            ans[i].push_back(end);
            sol.push_back(ans[i]);
        }
    }
};
int main(){
    Solution sol;
    string s = "a";
    string e = "c";
    unordered_set<string >dict;
    dict.insert("a");
    dict.insert("b");
    dict.insert("c");
    vector<vector<string>> ans = sol.findLadders(s,e,dict);
    for(int i = 0; i < ans.size();i++){
        cout<<""<<endl;
        for(int j = 0; j < ans[i].size() ;j++)
            cout<<ans[i][j]<<" ";
    }
}
