public class Solution {
    public int countComponents(int n, int[][] edges) {
        int[] visited = new int[n];
        int rst = 0;
        HashMap<Integer,ArrayList<Integer>> map = new HashMap<>();
        for(int i = 0; i < n; i++){
        	map.put(i,new ArrayList<Integer>());
        }
        for(int[] edge: edges){
        	map.get(edge[0]).add(edge[1]);
        	map.get(edge[1]).add(edge[0]);
        }
        for(int i = 0; i < n; i++){
        	if(visited[i] == 0){
        		dfs(i,map,visited,new int[n]);
        		rst++;
        	}
        }
        return rst;
    }
    public void dfs(int node, HashMap<Integer,ArrayList<Integer>> map ,int[] visited,int[] path){
    	visited[node] = 1;
    	path[node] = 1;
    	Queue<Integer> queue = new LinkedList<>();
    	for(int i = 0; i < map.get(node).size(); i++){
    		queue.add(map.get(node).get(i));
    	}
    	while(!queue.isEmpty()){
    		node = queue.poll();
    		visited[node] = 1;
    		path[node] = 1
    		for(int i = 0;i < map.get(node).size(); i++){
    			int tmp = map.get(node).get(i);
    			if(path[tmp] == 0){
    				queue.add(tmp);
    			}
	    	}
    	}
    	return;
    }
}