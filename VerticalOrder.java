public class Solution {
	int min = 0;
	int max = 0;
    public List<List<Integer>> verticalOrder(TreeNode root) {
        HashMap<Integer,ArrayList<Integer>> map = new HashMap<>();
        List<List<Integer>> rst = new ArrayList<ArrayList<Integer>>();
        traverse(root,0,map);
        for(int i = min; i <=max; i++){
        	if(map.containsKey(i)){
        		List<Integer> list = map.get(i);
        		rst.add(list);
        	}
        }
        return rst;

    }
    public void traverse(TreeNode root, int level,HashMap<Integer,ArrayList<Integer>> map){
    	if(root == null){
    		return;
    	}
    	Queue<TreeNode> queue = new LinkedList<>();
    	List<Integer> lvls = new ArrayList<>();
    	queue.add(root);
    	lvls.add(level);
    	int i = 0;
    	while(!queue.isEmpty()){
    		TreeNode node = queue.poll();
    		int lvl = lvls.get(i++);
	    	if(map.containsKey(lvl)){
	    		map.get(lvl).add(node.val);
	    	}
	    	else{
	    		ArrayList<Integer> list = new ArrayList<>();
	    		list.add(node.val);
	    		map.put(lvl,list);
	    	}
    		if(node.left != null){
    			queue.add(node.left);
    			lvls.add(lvl-1);
    		}
    		if(node.right != null){
    			queue.add(node.right);
    			lvls.add(lvl+1);
    		}
    	}	
    }
}