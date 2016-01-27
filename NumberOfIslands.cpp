class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int m = grid.size();
        if(m == 0){
        	return result;
        }
        int n = grid[0].size();
        if(n == 0){
        	return result;
        }
        bool noIsland = false;
        while(!noIsland){
        	bool findIs = false;
        	for(int i = 0; i < m; i++){
        		for(int j = 0; j < n; j++){
        			if(grid[i][j] == '1'){
        				dfs(i,j,m,n,grid);
        				findIs = true;
        				result++;
        			}
        		}
        	}
        	if(findIs == false){
        		noIsland = true;
        	}
        }
        return result;
    }
    void dfs(int i,int j,int m,int n, std::vector<std::vector<char>>& grid){
        vector<int> stack; 
        stack.push_back(i*n+j);
       	while(!stack.empty()){
       		int pos = stack.back();
       		stack.pop_back();
       		int row = pos / n;
       		int col = pos % n;
       		grid[row][col] = '0';
       		if(row-1 >= 0 && grid[row-1][col] == '1'){
       			
       			stack.push_back((row-1)*n+col);
       		}
       		if(row+1 < m && grid[row+1][col] == '1'){
       	
       			stack.push_back((row+1)*n+col);
       		}
       		if(col-1>=0 && grid[row][col-1] == '1'){
       	
       			stack.push_back(row*n+col-1);
       		}
       		if(col+1  < n && grid[row][col +1] == '1'){

       			stack.push_back(row*n+col+1);
       		}

       	}
    } 
};