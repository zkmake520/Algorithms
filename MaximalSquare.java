public class Solution {
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length;
        if(m == 0){
        	return 0;
        }
        int n = maxtrix[0].length;
        if(n == 0){
        	return 0;
        }
        int [][] score = new int[m][n];
        if(matrix[0][0] == '1'){
        	score[0][0] = 1;
        }
        for(int i = 1;i < n;i++){
        	int tmp = 0;
        	if(matrix[0][i] == '1'){
        		tmp =1;
        	}
        	score[0][i] = score[0][i-1]>tmp?score[0][i-1]:tmp;
        }
        for(int i = 1;i < m;i++){
        	int tmp = 0;
        	if(matrix[i][0] == '1'){
        		tmp =1;
        	}
        	score[i][0] = score[i-1][0]>tmp?score[i-1][0]:tmp;
        }
        for(int i = 2;i < m; i++){
        	for(int j = 2; j < n; j++){
        		if(maxtrix[i][j] == '0'){
        			score[i][j] = score[i-1][j] > score[i][j-1]?score[i-1][j]: score[i][j-1];
        		} else{
        			int tmp = getScore(i,j,matrix);
        			int tmp2 = score[i-1][j] > score[i][j-1]?score[i-1][j]: score[i][j-1];
        			score[i][j] = tmp > tmp2?tmp:tmp2;
        		}
        	}
        }
        return score[m-1][n-1];
    }
    int getScore(int row,int col, char [][] matrix){
    	int max = 1;
    	int std = row>col?col:row;
    	int side = 1;
    	while( side <= std){
    		int stR = row-side;
    		int stC = col-side;
    		for(int i = row; i >= stR ; i--){
    			if(matrix[i][stC] == '0'){
    				return max;
    			}
    		}
    		for(int i = col; i >= stC; i--){
    			if(matrix[stR][i] == '0'){
    				return max;
    			}
    		}
    		max = (side+1)*(side+1);
    	}
    	return max;
    }
}