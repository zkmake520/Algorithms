#include<iostream>
#include<string>
#include<cstdlib>
#include <vector>

using namespace std;
class Solution{
public:
    int evalRPN(vector<string> &tokens){
        int answer;
        vector<int> numbers;
        vector<string>::iterator iter;
        vector<int>::iterator iter2;
        for(iter = tokens.begin(); iter!=tokens.end(); iter++){
            if(*iter == "+"){
                iter2 = numbers.end();
                iter2--;
                int n1 = *iter2--;
                int n2 = *iter2;
                numbers.pop_back();
                numbers.pop_back();
                numbers.push_back(n1+n2);

            }
            else if(*iter == "-"){
                iter2 = numbers.end();
                iter2--;
                int n1 = *iter2--;
                int n2 = *iter2;
                numbers.pop_back();
                numbers.pop_back();
                numbers.push_back(n2-n1);

            }
            else if(*iter == "*"){
                iter2 = numbers.end();
                iter2--;
                int n1 = *iter2--;
                int n2 = *iter2;
                numbers.pop_back();
                numbers.pop_back();
                numbers.push_back(n1*n2);

            }
            else if(*iter == "/"){
                iter2 = numbers.end();
                iter2--;
                int n1 = *iter2--;
                int n2 = *iter2;
                numbers.pop_back();
                numbers.pop_back();
                numbers.push_back(n2/n1);


            }
            else
            {
                string str = *iter;
                numbers.push_back(atoi(str.c_str()));
                iter2 = numbers.end();


            }
        }
        iter2 = numbers.end()-1;
        return *iter2;
    }
};
int main()
{
    Solution sol;

    vector<string>  tokens;
    for(int i = 0; i <5;i++)
    {
        string str;
        cin>>str;
        tokens.push_back(str);
    }
    sol.evalRPN(tokens);

}
