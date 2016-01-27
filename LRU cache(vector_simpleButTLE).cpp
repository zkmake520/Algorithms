#include<iostream>
#include<cstdlib>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class LRUCache{
public:

    vector<int> keys;  //Least recently used 可以用一个栈来实现，新的元素就放入栈顶
    unordered_map<int,int>map;
    int limit;
    LRUCache(int capacity) {
        limit = capacity;
    }

    int get(int key) {
        int ifFind = 0;
         vector<int>:: iterator iter =find(keys.begin(),keys.end(),key);
        if(iter == keys.end())
            return -1;
        else {
            keys.erase(iter);
            keys.push_back(key);
            return map[key];
        }
    }

    void set(int key, int value) {
        if(keys.size() == limit){
            //此时要删除元素
            vector<int>::iterator iter = keys.begin();
            int key = *iter;
            keys.erase(keys.begin());
            map.erase(key);

        }
        vector<int>::iterator iter2 = find(keys.begin(),keys.end(),key);
        if(iter2 != keys.end()){
            keys.erase(iter2);
        }
        keys.push_back(key);
        map[key] = value;
    }
};
int main(){
    LRUCache sol(2);
    cout<<sol.get(2)<<endl;
    sol.set(2,6);
    cout<<sol.get(1)<<endl;
    sol.set(1,5);
    sol.set(1,2);
    cout<<sol.get(1)<<endl;
    cout<<sol.get(2)<<endl;


}
