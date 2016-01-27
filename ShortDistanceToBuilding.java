public class ShortestDistanceToBuilding {
    public int shortestDistance(int[][] grid) {
    	int m = grid.length;
    	if(m <= 0){
    		return -1;
    	}
    	int n = grid[0].length;
    	if(n <= 0){
    		return -1;
    	}
    	int[][] visited = new int[m][n];
    	int[][] distance = new int[m][n];
    	int rst= -1;
    	int buildings= 0;
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(grid[m][n] == 1){
    				buildings ++;
	    			Queue<int[]> queue = new LinkedList<int[]>();
	    			int[][] path = new int[m][n];
	    			queue.add(new int[]{i,j});
	    			int level = 0;
	    			while(!queue.isEmpty()){
	    				int [] position = queue.poll();
	    				int r = position[0];
	    				int c = position[1];
	    				visited[r][c] ++;
	    				distance[r][c] += level;
	    				level++;
	    				if(r >=1 && path[r-1][c] == 0 && grid[r-1][c] == 0){
	    					queue.add(new int[]{r-1,c});
	    					path[r-1][c] =1;
	    				}
	    				if(r < m-1 && path[r+1][c] == 0&& grid[r+1][c] == 0){
	    					queue.add(new int[]{r+1,c});
	    					path[r+1][c] =1;
	    				}
	    				if(c < n-1 && path[r][c+1] == 0&& grid[r][c+1] == 0){
	    					queue.add(new int[]{r,c+1});
	    					path[r][c+1] =1;
	    				}
	    				if(c >=1 && path[r][c-1] == 0&& grid[r][c-1] == 0){
	    					queue.add(new int[]{r,c-1});
	    					path[r][c-1] =1;
	    				}
	    			}
    			}
    		}
    	}
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(grid[i][j] == 0 && visited[i][j] == buildings){
    				rst = rst==-1?distance[i][j]: Math.min(rst,distance[i][j]);
    			}
    		}
    	}
    	return rst;

    }
    public static void main(String[] args){
    	ShortestDistanceToBuilding sol = new ShortestDistanceToBuilding();
    	int [][] grid = {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    	sol.shortestDistance(grid);
    }
}