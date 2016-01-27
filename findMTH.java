public class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<Integer>;
        HashMap<Integer,Integer> heights = new HashMap<>();
        int handledCount = 0;
        for(int i = 0;i < n; i++){
        	heights.put(i,Integer.MAX_VALUE);
        	for (int j = 0; j < n;j++){
        		if(edges[i][j] != 0){
        			edges[j][i] = edges[i][j];
        		}
        	}
        }
        int start = 0;
        while(handledCount < n){
        	if(heights[start] != Integer.MAX_VALUE);
        	int height = getHeight(start,edges);
        }
    }
    int getHeight(int root, int[][] edges){
    	LinkedList<Integer> list = new LinkedList<>();
    	list.add(root);
    	int height = -1;
    	while(!list.isEmpty()){
    		height ++;
    		int node = list.pop();
    		for(int i = 0; i < n; i++){
    			if(i == node || edges[node][i] == 0){
    				continue;
    			}
    			else{
    				list.add(i);
    			}
    		} 
    	}
    	return height;
    }
}