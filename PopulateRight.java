public class Solution {
    public void connect(TreeLinkNode root) {
    	while(root != null){
    		TreeLinkNode cur = root;
    		while(cur != null){
    			if(cur.left != null && cur.right != null){
    				cur.left.next =cur.right;
    			}
                if(cur.left != null && cur.right == null){
                    
                }
    			if(cur.right !=null ){
    				if(cur.next != null){
    					cur.right.next = cur.next.left;
    				}
    				else{
    					cur.right.next = null;
    				}
    			}
    			cur = cur.next;
    		}
    		root = root.left;
    	}
    	return ;
    }
}