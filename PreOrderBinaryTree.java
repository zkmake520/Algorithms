public class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        StacK<TreeNode> stack = new Stack<>();
        TreeNode node = root;
        while(true){
        	list.add(node.val);
        	if(node.right != null){
        		stack.push(node.right);
        	}
        	if(node.left != null){
        		node = node.left;
        	}
        	else{
        		if(stack.isEmpty()){
        			break;
        		}
        		else{
        			node = stack.pop();
        		}
        	}
        }
        return list;
    }
}