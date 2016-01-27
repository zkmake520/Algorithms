public class Solution {
    public int minArea(char[][] image, int x, int y) {
    	if(image.length == 0){
    		return 0;
    	}
        int minX = image.length; 
        int maxX = 0;
        int minY = image[0].length;
        int maxY = 0;
        boolean [][] visited = new boolean[image.length][image[0].length];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x,y});
        visited[x][y] = true;
        while(!queue.isEmpty()){
        	int[] pos = queue.poll();
        	x = pos[0];
        	y = pos[1];
        	minX = Math.min(minX,x);
        	maxX = Math.max(maxX,x);
        	minY = Math.min(minY,y);
        	maxY = Math.max(maxY,y);
        	if(x>=1 && visited[x-1][y] == false && image[x][y-1] == '1'){
        		visited[x-1][y] = true;
        		queue.add(new int[]{x-1,y});
        	}
        	if(y>=1 && visited[x][y-1] == false && image[x][y-1] == '1'){
        		visited[x][y-1] = true;
        		queue.add(new int[]{x,y-1});
        	}
        	if(x<image[0].length-1 && visited[x+1][y] == false && image[x+1][y] == '1'){
        		visited[x+1][y] = true;
        		queue.add(new int[]{x+1,y});
        	}
        	if(y<image[0].length-1 && visited[x][y+1] == false && image[x][y+1] == '1'){
        		visited[x][y+1] = true;
        		queue.add(new int[]{x,y+1});
        	}
        }
        if (maxX-minX < 0 || maxY-minY){
        	return 0
        }
        return (maxY-minY+1) * (maxX - minX+1);
    }
}