#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution{
public:
    int minDepth(TreeNode *root){
        queue<TreeNode *> que;
        if(root == NULL)    return 0;
        que.push(root);
        root->val = 1;
        while(!que.empty()){
            TreeNode *cur = que.front();
            que.pop();
            if(cur->left == NULL && cur->right ==NULL)
                return cur->val;
            if(cur->left !=NULL){
                que.push(cur->left);
                cur->left->val = cur->val+1;
            }
            if(cur->right !=NULL){
                que.push(cur->right);
                cur->right->val =cur->val+1;
            }
        }
    }

};
