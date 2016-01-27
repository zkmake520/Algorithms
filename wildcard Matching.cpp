#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<ostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<queue>
#include<unordered_map>
int beg, des;
using namespace std;
#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<ostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    //类似与递归但是递归会超时
    bool isMatch(const char *s, const char *p) {
        const char * starPos = NULL;
        const char * matchPos = NULL;
        while(*s){
            if(*s == *p || *p == '?'){
                s++,p++;
                continue;
            }
            if(*p == '*'){
                starPos = p;
                matchPos = s;
                p++;
                continue;
            }
            if(starPos){
                p = starPos+1;
                s = matchPos+1;
                matchPos++;
                continue;
            }
            return false;
        }
        while(*p == '*') p++;
        if(*p)  return false;
        return true;
    }
    
};
int main(){
    Solution sol;
    cout<<sol.isMatch("a","*a*");
}

