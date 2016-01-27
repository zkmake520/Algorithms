public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode root = null;
        ListNode cur = null;
        PriorityQueue<Elem> queue = new PriorityQueue<>();
        for(int i = 0;i < lists.length;i ++){
        	queue.add(new Elem(i,0,lists[i]));
        }
        while(!queue.isEmpty()){
        	Elem smallest = queue.poll();
        	if(root == null){
        		root = smallest.node;
        		cur = smallest.node;
        	}
        	else{
        		cur.next = smallest.node;
        	}
        	if(smallest.node.next !=null){
        		queue.add(new Elem(smallest.row,0,smallest.node.next));
        	}
        }
        return root;
    }
    class Elem implements Comparable<Elem>{
    	int row;
    	int col
    	ListNode node;
    	Elem(int row,int col,ListNode node){
    		this.row = row;
    		this.col = col;
    		this.node = node;
    	}
    	@Override
    	public int compareTo(Elem other){
    		return Integer.compare(this.node.val,other.node.val);
    	}

    }
}