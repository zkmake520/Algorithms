import java.util.*;
public class RangeSum {
    int [][] matrixSums;
    public RangeSum(int[][] matrix) {
        matrixSums = new int [matrix.length+1][matrix[0].length+1];
        for( int i = 0; i < matrix[0].length;i++){
            matrixSums[0][i] = 0;
        }
        for( int i = 0; i < matrix.length;i++){
            matrixSums[i][0] = 0;
            
        }
        for(int i = 1 ; i<= matrix.length; i++){
            int sum = 0;
            for(int j = 1; j <= matrix[0].length;j++){
                sum += matrix[i-1][j-1];
                matrixSums[i][j] = matrixSums[i-1][j]+sum;
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
         System.out.println(matrixSums[4][3]+":"+matrixSums[2][3]+":"+matrixSums[4][1]+":"+matrixSums[2][1]);
        return matrixSums[row2][col2] - matrixSums[row1][col2]-matrixSums[row2][col1]+matrixSums[row1][col1];
    }
    public static void main(String[]args){
        int [][]mm = new int[][]{{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
        RangeSum m = new RangeSum(mm);
        System.out.println(m.sumRegion(2, 1, 4, 3));
        System.out.println(m.sumRegion(1, 1, 2, 2));
        System.out.println(m.sumRegion(1, 2, 2, 4));
        return ;
    }
}
