#include<iostream>
#include<vector>
#include<cstdlib>
#include<unordered_map>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL) {}
};
class Solution{
public:
	ListNode *deleteDuplicates(ListNode *head){
		unordered_map<int,int> map;
		ListNode *nhead = new ListNode(-1);
		ListNode *root = head;
		bool flag= false;
		while(root !=NULL){
			if(root->val == root->next->val){
				root = root->next;
				while(root->next != NULL && root->val == root->next->val ){
					root = root->next;
				}
				nhead->next = root->next;
				root = root->next;
			}
			else{
				nhead->next = root;
				root = root->next;
			}
		}
		return nhead->next;
	}

};
int main(){
    Solution sol;
    ListNode node[10];
    node[1].val = 1;
    node[2].val = 2;
    node[3].val = 2;
    node[4].val = 3;
    node[1].next = &node[2];
     node[2].next = &node[3];
      node[3].next = &node[4];
       node[4].next = NULL;

    sol.deleteDuplicates(&node[1]);
}