public class Solution {
    public int maximalRectangle(char[][] matrix) {
    	int m = matrix.length;
    	if(m == 0){
    		return 0;
    	}
    	int n = matrix[0].length;
    	if(n == 0){
    		return 0;
    	}
       	int [][]B = new int [m][n];
       	int [][]H = new int [m][n];
       	int max = -1;
       	for(int i = 0;i <m; i++){
       		for(int j = 0; j < n;j ++){
       			if(matrix[i][j] == '0'){
       				B[i][j] = 0;
       				H[i][j] = 0;
       			}
       			else{
	       			if(i >= 1 && j >=1){
       					int b = j;
       					while(b>=0 && matrix[i][b] =='1'){
       						b--;
       					} 
       					int h = i;
       					while(h>=0 && matrix[h][j] =='1'){
       						h--;
       					}	
       					int bLen = j-b;
       					int hLen = i-h;
       					if(B[i-1][j-1] == 0){
       						
       						if(bLen > hLen){
       							B[i][j] = bLen;
       							H[i][j] = 1;
       						}
       						else{
       							B[i][j] = 1;
       							H[i][j] = hLen;
       						}
       					}
       					else{
       						B[i][j] = bLen > B[i-1][j-1]?B[i-1][j-1]+1:bLen;
       						H[i][j] = hLen> H[i-1][j-1]?H[i-1][j-1]+1:hLen;
       					}
	       			}
	       			else if(i >=1){
	       				B[i][j] = 1;
	       				H[i][j] = H[-1][j] > 0?H[-1][j]+1:1;
	       			}
	       			else if(j >=1){
	       				B[i][j] = B[i][j-1] >0?B[i][j-1]+1:1;
	       				H[i][j] = 1
	       			}
	       			else{
	       				H[i][j] = B[i][j] = matrix[i][j] == '1'?1:0;
	       			}
       			}
       			if(B[i][j] * H[i][j] > max){
       				max = B[i][j] * H[i][j];
       			}
       		}

       	}
       	return max;
    }
}