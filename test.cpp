#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    int dfs(TreeNode *root, int path)
    {
        if(root == NULL)
           return 0;
        path = path * 10 + root->val;
        if(root->left == NULL && root->right == NULL)
            return path;
        return dfs(root->left, path) + dfs(root->right, path);
    }

    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int path = 0;
        return dfs(root, path);
    }
};
int main(){
    Solution sol;
    TreeNode *h1 = new TreeNode(1);
    TreeNode *h2 = new TreeNode(2);
    TreeNode *h3 = new TreeNode(3);
    TreeNode *h4 = new TreeNode(4);
    TreeNode *h5 = new TreeNode(5);
    h1->left = h2;
    h1->right = h3;
    h2->left = h4;
    h2->right = h5;
    h3->left = NULL;
    h3->right = NULL;
    h4->left = NULL;
     h4->right = NULL;
     h5->left = NULL;
     h5->right = NULL;

    cout<<sol.sumNumbers(h1);
}
