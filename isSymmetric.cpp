#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<unordered_map>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL),right(NULL){}
}
class Solution{
public:
	bool compare(TreeNode *root, TreeNode *revRoot){
		if(root == NULL && revRoot == NULL)
			return true;
		else if(root == NULL && revRoot !=NULL)
			return false;
		else if(root != NULL && revRoot == NULL)
			return false;
		else if(root->val != revRoot->val)
			return false;
		return compare(root->left, revRoot->right)&&compare(root->right,revRoot->left);

	}
	bool isSymmetric(TreeNode *root){
		TreeNode *revRoot = root;
		return bool compare(root->left, revRoot->rigth);
			
	}

}
int main(){
	Solution sol;
	TreeNode *a1 = new TreeNode(1);
	TreeNode *a2 = new TreeNode(2);
	TreeNode *a3 = new TreeNode(2);
	TreeNode *a4 = new TreeNode(3);
	TreeNode *a5 = new TreeNode(3);
    TreeNode *a6 = new TreeNode(4);
    TreeNode *a7 = new TreeNode(4);
    a1->left = a2;
    a1->right = a3;
    a2->left = a4;
    a2->right = a6;
    a3->left = a5;
    a3->right = a7;
    a4->left = NULL;
    a5->left = NULL;
    a6->left = NULL;
    a7->left = NULL;
    a4->right = NULL;
    a5->right = NULL;
    a6->right = NULL;
    a7->right = NULL;
    cout<<sol.isSymmetric(a1);
}
