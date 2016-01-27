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
    int sumNumbers(TreeNode *root) {
        if(root == NULL)    return 0;
        vector<int> numbers;
        vector<int> len;
        int num = 0;
        int high =  0;
        int sum = 0;
        Dfs(root,num,high,numbers,len);
        for(int i = 0; i < numbers.size(); i++){
          sum += numbers[i];
        }
        return sum;
    }
    void Dfs(TreeNode *root,int num, int high, vector<int> &numbers,vector<int> &len){
        if(root == NULL)  {
            numbers.push_back(num);
            len.push_back(high);
            return;
        }
        num = 10*num+root->val;
        if(root->left ==NULL && root->right ==NULL)
             Dfs(root->left, num, high+1,numbers,len);
        else
        {   if(root->left !=NULL)
                Dfs(root->left, num, high+1,numbers,len);
            if(root->right !=NULL)
                Dfs(root->right,num,high+1,numbers,len);
        }
        return;
    }


};
int main(){
    Solution sol;
     TreeNode *h1 = new TreeNode(4);
    TreeNode *h2 = new TreeNode(9);
    TreeNode *h3 = new TreeNode(0);

    TreeNode *h5 = new TreeNode(1);
    h1->left = h2;
    h1->right = h3;
    h2->left = NULL;
    h2->right = h5;
    h3->left = NULL;
    h3->right = NULL;

     h5->left = NULL;
     h5->right = NULL;


    cout<<sol.sumNumbers(h1);
}
