public class Solution {
    public int countNodes(TreeNode root) {
        int leftDepth = countLeft(root,1);
        int rightDepth = countRight(root,2); 
        if(leftDepth == rightDepth){
            return Math.pow(2,leftDepth+1)-1;
        }
        else{
            return 1+countNodes(root->left) + countNodes(root->right);
        }
    }

    int count(TreeNode root,int direction){
    	int depth = 0;
        if(direction == 1){
    	   while(root.left!=null){
    		  root = root->left;
    		  depth++;
    	   }
        }
        else{
            while(root.right !=null){
                root = root->right;
                depth++;
            }
        }
        return depth;
    }
}