import java.util.*;

/*  problem how to validate BST?

	Solution1: do inorder traversal, the value should be in increasing order

	*/
public boolean isValidBST(TreeNode root) {
    Stack<TreeNode> stack = new Stack<>();
    List<Integer> list = new ArrayList<>();
    TreeNode cur = root;
    TreeNode pre = null;
    while(!stack.isEmpty() || cur != null){
        if(cur !=null ){
            stack.push(cur);
            cur = cur.left;
        } else{
            cur = stack.pop();
            if(pre != null && cur.val <= pre.val){
            	return false;
            }
            pre = cur;
            cur = cur.right;
        }
    }
    return true;
}



/*Solution2: Recursion, for each node there should be a range for it. which means that min< root.val <max
	 thus if we have range for current root, then we can get the range for its left and right node 
	 left: min<left < root.val     right: root.val < right < max
*/
public boolean isValidBST(TreeNode root) {
    return helper(root, Long.MIN_VALUE, Long.MAX_VALUE);
}
public boolean helper(TreeNode root, long min, long max){
    if(root == true)    return true;
    if(root.val <=min && root.val >= max)    return false;
    return helper(root.left,min,root.val) && helper(root.right,root.val,max);
}