
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> sta;
        vector<TreeNode *> nodes;
        unordered_map<TreeNode *,int>map;
        if(root == NULL)
            return res;
        nodes.push_back(root);
        sta.push_back(root->val);
        while(!nodes.empty()){
            TreeNode *tmp = nodes[nodes.size()-1];
            int ans =0;
            
           
            if(map.find(tmp) !=map.end())
                map[tmp] +=1;
            else{
                for(int i =0;i < sta.size();i++)
                    ans += sta[i];
                if(ans == sum)
                    res.push_back(sta);
                map[tmp] = 0;
            }
            if(map[tmp] != 0){
                nodes.pop_back();
                sta.pop_back();
                continue;
            }
            if(tmp->right!=NULL){
                nodes.push_back(tmp->right);
                sta.push_back(tmp->right->val);
            }
            if(tmp->left!=NULL){
                nodes.push_back(tmp->left);
                sta.push_back(tmp->left->val);
            }
        }
        return res;
        
    }
};