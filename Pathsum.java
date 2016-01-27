/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
       	return helper(root,sum,0);
    }
    private void helper(TreeNode root, int sum ,int cur){
    	if(root ==null){
    		if(cur == sum){
    			return true;
    		}
    		else{
    			return false;
    		}
    	}
    	boolean left = helper(root.left,sum,root.val+cur);
    	if(left == true){
    		return true;
    	}
    	boolean right = helper(root.right,sum,root.val+cur);
    	if(right == true){
    		return true;
    	}
    	return false;
    }
}