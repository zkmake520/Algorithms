//
//  lengthOfLongestSubString.cpp
//
//
//  Created by zkwangchao on 14-4-8.
//
//

#include<iostream>
#include<vector>
#include<string>
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
    vector<TreeNode *>generate(int lef,int rig){
        vector<TreeNode *> ret;
        vector<TreeNode *> right;
        if(rig == lef){
            TreeNode *node = new TreeNode(lef);
            ret.push_back(node);
            return ret;
        }
        for(int i = lef; i <= rig; i++){ //used as root respectively
            vector<TreeNode *> left,right;
            if(i-1 >= lef)
                left = generate(lef, i-1);
            if(rig >= i+1)
                right= generate(i+1, rig);
            int a = (left.size() == 0)?1:0;
            int b = (right.size() == 0)?1:0;
            if(a == 0){
                for(int j = 0; j < left.size();j++){
                    if(b == 0){
                        for(int k = 0 ; k < right.size();k++){
                            TreeNode *node = new TreeNode(i);
                            node->left = left[j];
                            node->right = right[k];
                            ret.push_back(node);
                        }
                    }
                    else{
                        TreeNode *node = new TreeNode(i);
                        node->left = left[j];
                        node->right = NULL;
                        ret.push_back(node);
                    }
                }
            }
            else{
                for(int k = 0 ; k < right.size();k++){
                    TreeNode *node = new TreeNode(i);
                    node->left = NULL;
                    node->right = right[k];
                    ret.push_back(node);
                }
            }
            
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *>ret;
        
        if(n < 1){
            ret.push_back(NULL);
            return ret;
        }
        //  cout<<1<<endl;
        return generate(1,n);
        
    }
    
};
int main(){
    
    Solution sol;
    // cout<<1<<endl;
    vector<TreeNode *>ret = sol.generateTrees(3);
    cout<<1<<endl;
}