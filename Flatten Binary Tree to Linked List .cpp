#include<iostream>
#include<vector>
#include<cstdlib>
#include<unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
   // TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
   void flatten (TreeNode *root) {
        vector<TreeNode*> tree;
        vector<TreeNode*> order;
        TreeNode *head =root;
        unordered_map<TreeNode*,int> map;
        map.clear();
        if(root == NULL)
            return ;

        tree.push_back(root);
        while(!tree.empty()){
            if(map[root]!= 1)
                order.push_back(root);
            if(root->right == NULL && root->left ==NULL || map[root] == 1){
                tree.pop_back();
                vector<TreeNode *>::iterator iter = tree.end();
                iter--;
                root = *iter;
            }
            else{
                map[root]  = 1;
                if(root->right != NULL)
                    tree.push_back(root->right);
                if(root->left != NULL)
                    tree.push_back(root->left);
                if(root->left != NULL)
                    root= root->left;
                else
                    root= root->right;
            }

        }
        for(int i = 0; i< order.size()-1;i++){
            order[i]->right =order[i+1];
            order[i]->left = NULL;

        }
        order[order.size()-1]->left =NULL;
        order[order.size()-1]->right = NULL;
      /*  while(head!=NULL){
            cout<<head->val;
            head= head->right;
        }*/
    }
};
int main(){
    Solution sol;
    TreeNode node[10];
    node[1].left = &node[2];
    node[1].val = 1;
    node[1].right = &node[3];
    node[2].val = 2;
    node[2].left = NULL;
    node[2].right = NULL;
    node[3].left = &node[4];
    node[3].right = NULL;
    node[3].val = 3;
    node[4].val = 4;
    node[4].left = NULL;
    node[4].right = NULL;
    sol.flatten(&node[1]);
}
