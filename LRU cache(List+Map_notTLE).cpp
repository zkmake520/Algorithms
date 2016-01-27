#include<iostream>
#include<cstdlib>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class LRUCache{
public:
    struct Node{
        int key;
        int val;
        Node *pre;
        Node *next;
    };
    unordered_map<int,Node*>map;

    Node *head;
    Node *tail;
    int limit;
    LRUCache(int capacity) {
        limit = capacity;

        map.clear();
		head= new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        unordered_map<int,Node*>:: iterator iter =map.find(key);

        if(iter == map.end())
            return -1;
        else {
            Node *node = iter->second;
            node->pre->next = node->next;
         //   cout<<"a"<<endl;
            node->next->pre = node->pre;
         //   cout<<"a"<<endl;
            toHead(iter->second);
            return node->val;
        }
    }
    void set(int key, int value) {
         unordered_map<int,Node *>::iterator iter = map.find(key);

        if(iter != map.end())//find
        {
           // cout<<"a"<<endl;
          // cout<<"a"<<endl;
       //   cout<<"a"<<endl;
            Node *node = iter->second;
            node->pre->next = node->next;
            node->next->pre = node->pre;
            toHead(iter->second);
          //  cout<<"a"<<endl;
            node->val = value;
          //  cout<<"a"<<endl;
        }
        else{
            if(map.size() == limit){
                //此时要删除元素
              //  cout<<"a"<<endl;
                Node *node = tail->pre;
                node->pre->next = tail;
                tail->pre = node->pre;
                map.erase(node->key);

            }

            Node *node = new Node();
            node->key = key;
            node->val = value;

            toHead(node);

            map[key] = node;

        }
}
    void toHead(Node * node){

        node->next = head->next;
       // cout<<"a"<<endl;
        node->next->pre = node;
        head->next = node;
        node->pre = head;

    }
};
int main(){
    LRUCache sol(1);
	 sol.set(2,1);
    cout<<sol.get(2)<<endl;
    sol.set(3,2);
    cout<<sol.get(2)<<endl;
	cout<<sol.get(3)<<endl;



}
