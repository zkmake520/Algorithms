#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	std::vector<int> v;
		if (root == NULL){
			return v;
		}        
		queue<TreeNode *> stack;
		stack.push(root);
		queue<int> level;
		level.push(0);
		while(!stack.empty()){
			TreeNode *tmp = stack.front();
			stack.pop();
			int tmpLvl = level.front();
			level.pop();
			if(v.size() <= tmpLvl){
				v.push_back(tmp.val);
			}
			else{
				v[tmpLvl] = tmp.val;
			}
			if(tmp.left != NULL){
				stack.push(tmp.left);
				level.push(tmpLvl+1);
			}
			if(tmp.right != NULL){
				stack.push(tmp.right);
				level.push(tmpLvl+1);
			}
		}
		return v;
    }
};

