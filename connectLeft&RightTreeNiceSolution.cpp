
#include<iostream>
#include<vector>

using namespace std;

struct TreeLinkNode {
int val;
TreeLinkNode *left, *right, *next;
TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
class Solution {
public:
    void connect(TreeLinkNode *root) {  //通过父节点的next来找这个子节点的next！！
        TreeLinkNode *start = root;
        while(root != NULL){
            start = root;
            if(start->left != NULL){
                while(start!= NULL){
                    start->left->next = start->right;
                    if(start->next!=NULL){
                        start->right->next = start->next->left;
                    }
                    else break;
                    start = start->next;
                }
            }
            root = root->left;
        }
    }
};
