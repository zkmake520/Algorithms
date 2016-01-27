#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *next = NULL;  //first start node on next level;
        TreeLinkNode *prev = NULL; //previous node of each level;
        while(root){
            next = prev = NULL;
            for(;root;root = root->next){
                if(!next)   next =  root->left?root->left:root->right;
                if(root->left){
                    if(prev) prev->next = root->left;
                    prev = root->left;
                }
                if(root->right){
                    if(prev)  prev->next = root->right;
                    prev = root->right;
                }
            }
            root = next;
        }
    }
};
