public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    	List<TreeNode> path1 = new ArrayList<TreeNode>();
        findNode(root,p,path1);
        List<TreeNode> path2 = new ArrayList<TreeNode>();
        findNode(root,q,path2);
        for(int i = 0; ;i++){
        	if(path1.get(i).val == path2.get(i).val){
        		continue;
        	}
        	else{
        		i--;
        	}
        }

        return path1.get(i);
    }
    boolean findNode(TreeNode root, TreeNode p, List<TreeNode> path){
    	if(root == null){
    		return false;
    	}
    	path.add(root);	
    	if(root.val == p.val){
    		return true;
    	}
    	boolean re = findNode(root.left,p,path);
    	if(re == true){
    		return true;
    	}
    	boolean re = findNode(root.right,p,path);
    	if(re == true){
    		return true;
    	}
    	path.remove(path.size()-1);
    	return false;
    }
}