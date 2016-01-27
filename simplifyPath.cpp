#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
public:
    string simplifyPath(string path){
        string path2 = "";
        vector<int> posOfSlash;
        vector<string> sta;
        if(path[path.size()-1] !='/')
            path.push_back('/');
        for (int i =0; i< path.size();i++){
            if(path[i] == '/'){
                path2.push_back(path[i]);
                while(path[i+1]=='/')
                    i++;
            }
            else path2.push_back(path[i]);
        }
        for(int i = 0; i < path2.size();i++){
            if(path2[i] == '/'){
                posOfSlash.push_back(i);
            }
        }
        int count =0;
        for(int i = 0; i < posOfSlash.size()-1;i++){
            if(path2.substr(posOfSlash[i]+1,posOfSlash[i+1]-posOfSlash[i]-1) == ".")
                continue;
            if(path2.substr(posOfSlash[i]+1,posOfSlash[i+1]-posOfSlash[i]-1) == ".."){
                if (sta.empty())
                    count++;
                else{
                    sta.pop_back();
                }
            }
            else {
                if(count !=0)
                    count--;
                else sta.push_back(path2.substr(posOfSlash[i]+1,posOfSlash[i+1]-posOfSlash[i]-1));
            }
        }
        string res= "";
        if(sta.size() == 0 )
            res +="/";
        for(int i =0;i < sta.size();i++){
            
            res +="/";
            res += sta[i];
        }
        return res;
    }
};
int main(){
	Solution sol;
	cout<<sol.simplifyPath("/home/");
}