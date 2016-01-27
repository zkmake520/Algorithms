public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
    	List<Integer> list = new ArrayList<Integer>();
        Stack<TreeNode> stack = new Stack<>();
        HashSet<TreeNode> set = new HashSet<>();
        stack.push(root);
        while(!stack.isEmpty()){
        	TreeNode node = stack.peek();
        	if(set.contains(node.left)){
        		list.add(node.val);
        		stack.pop();
        		set.add(node);
        	}
        	else{
	        	if(node.right != null){
	        		stack.push(node.right);
	        	}
	        	if(node.left != null){
	        		stack.push(node.left);
	        	}
	        }
        }
        return list;
    }
}