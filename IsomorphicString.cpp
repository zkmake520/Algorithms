#include<map>
#include<string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	int len = s.length();
    	map<char,char> v;
        for(int i = 0;i < len;i++){
        	if(v.find(s[i]) == v.end()){
        		v[s[i]] = t[i];
        	} else{
        		if(v[s[i]] == t[i] ){
        			continue;
        		}else{
        			return false;
        		}
        	}
        }
        map<char,char> v2;
        for(int i = 0;i < len;i++){
        	if(v2.find(t[i]) == v2.end()){
        		v2[t[i]] = s[i];
        	} else{
        		if(v2[t[i]] == s[i] ){
        			continue;
        		}else{
        			return false;
        		}
        	}
        } 
        return true;
    }
};