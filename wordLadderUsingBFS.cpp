#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end)    return 0;
        queue<string> vec;
      //  vector<int> len;
        unordered_map<string,int>mp;
        int shortLength = INT_MAX;
		int changed = 0;
        vec.push(start);
        mp[start] = 1;
        int step = 0;
        while(!vec.empty()){  //这边为了避免tle。一个非常好的做法是把当前的单词的每一个字母进行相应替换，这样就是26*wordLength。而不是把字典中的每个都进行查找一边
          //  cout<<2<<endl;
            string cur = vec.front();
            vec.pop();
            for(int i = 0;i < cur.size(); i++){
                string tmp = cur;
					//if(sign == 1)	break;
                for(char j = 'a'; j!='z'+1; j++){
                    tmp[i] = j;
                    if(tmp == end)  return mp[cur]+1;
                    if(dict.find(tmp) != dict.end() && mp.find(tmp) == mp.end()){
                        mp[tmp] = mp[cur]+1;
                        vec.push(tmp);
                    }
                }
            }

        }
    }
};
int main(){
    Solution sol;
    string s = "ait";
    string e = "cog";
    unordered_set<string >dict;
    dict.insert("hot");
    dict.insert("dot");
	dict.insert("aot");
    dict.insert("lot");
    dict.insert("dog");
    dict.insert("log");
    cout<<sol.ladderLength(s,e,dict);

}
