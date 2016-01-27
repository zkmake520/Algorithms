#include<iostream>
#include<vector>
#include<string>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x) , left(NULL),right(NULL){}
};
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxPathRoot = INT_MIN;
        return getPathSum(root,maxPathRoot);
    }
    int getPathSum(TreeNode *root,int &maxPathRoot){ //就一个递归，比较3种大小，一个是左子树和右子树还有就是经过root的最大值，特别要注意的是当经过左又子树的root
        int maxSum,maxPath;//的最大值小于0时，此时经过本root的最大值就是root-val
        int maxLeft,maxRight;
        int maxPathLeft,maxPathRight;
        if(root->left ==NULL && root->right ==NULL){
            maxPathRoot = root->val;
            return root->val;
        }
        maxLeft = maxRight = maxPathRight = maxPathLeft=INT_MIN;
        if(root->left !=NULL){
             maxLeft= getPathSum(root->left, maxPath);
             maxPathLeft = maxPath;
        }
        if(root->right!=NULL){
            maxRight = getPathSum(root->right,maxPath);
            maxPathRight = maxPath;
        }
        //  cout<<maxPathRoot<<endl;
        maxPath = maxPathRight>maxPathLeft?maxPathRight:maxPathLeft;
        if(maxPath >0 )
            maxPathRoot = maxPath+root->val;
        else
            maxPathRoot = root->val;
       // cout<<maxPathRoot<<endl;
        maxSum = maxRight>maxLeft?maxRight:maxLeft;
      //  cout<<maxSum<<endl;
        int tmp = maxPathRight>maxPathLeft?maxPathLeft:maxPathRight;
        if(tmp > 0){
               // cout<<tmp<<endl;
            maxSum = maxSum>(maxPathRoot+tmp)?maxSum:maxPathRoot+tmp;
        }
        else maxSum = maxSum>maxPathRoot?maxSum:maxPathRoot;
        return maxSum;
    }
};
int main(){
    Solution sol;
    TreeNode *h1 = new TreeNode(2);
    TreeNode *h2 = new TreeNode(-1);
    TreeNode *h3 = new TreeNode(2);
     TreeNode *h4 = new TreeNode(2);
    TreeNode *h5 = new TreeNode(3);
     TreeNode *h6 = new TreeNode(-3);
    TreeNode *h7 = new TreeNode(4);
    h1->left = h2;
    h1->right = NULL;
    h2->left =NULL;
    h2->right = NULL;
    h3->left = h6;
    h3->right =h7;
    h6->left = NULL;
    h6->right = NULL;
    h4->left = NULL;
    h4->right = NULL;
    h7->left = NULL;
    h7->right = NULL;
    h5->left = NULL;
    h5->right = NULL;
    cout<<sol.maxPathSum(h1);
}
