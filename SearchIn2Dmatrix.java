public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
    	if(matrix.length == 0 || matrix[0].length){
    		return false;
    	}
        return helper(matrix,target,0,matrix.length,0,matrix[0].length);
    }
    boolean helper(int[][] matrix,int target,int rowS,int rowE, int colS,int colE){
    	if(colS > colE || rowS > rowE){
    		return false;
    	}
    	if(rowS == rowE && colS ==colE){
    		return matrix[rowS][colS] == target;
    	}
    	int rowM = rowS + (rowE-rowS)/2;
    	int colM = colS +(colE-colS)/2;
    	int num = matrix[rowM][colM];
    	if(num ==  target){
    		return true;
    	}
    	else if(num < target){
    		return helper(matrix,target,rowS,rowM,colS,colM) || helper(matrix,target,rowM+1,rowE,colS,colM-1) ||
    				helper(matrix,target,rowS,rowM-1,colM+1,colE);
    	}
    	else{
    		return helper(matrix,target,rowM,rowE,colM,colE) || helper(matrix,target,rowM+1,rowE,colS,colM-1) ||
    				helper(matrix,target,rowS,rowM-1,colM+1,colE);
    	}
    }
}