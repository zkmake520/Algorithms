public class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
    	if(dungeon.length == 0 || dungeon[0].length == 0){
    		return 0;
    	}
    	int m = dungeon.length;
    	int n = dungeon[0].length;
        int [][] hp = new int[dungeon.length][dungeon[0].length];
        hp[m-1][n-1] = dungeon[m-1][n-1] < 0?dungeon[m-1][n-1]:0;
        for(int i = m-2; i >=0 ;i--){
        	hp[i][n-1] = dungeon[i][n-1]+hp[i+1][n-1] >0?0: dungeon[i][n-1]+hp[i+1][n-1];
        }
        for(int i = n-2; i >=0 ;i--){
        	hp[m-1][i] = dungeon[m-1][i]+hp[m-1][i+1] >0?0: dungeon[m-1][i]+hp[m-1][i+1];
        }
        for(int i =m-2;i >=0 ;i--){
        	for(int j = n-2;j>=0; j--){
        		hp[i][j] = Math.max(hp[i+1][j],hp[i][j+1]);
        		hp[i][j] += dungeon[i][j];
        		hp[i][j] = hp[i][j]>0?0:hp[i][j];
        	}
        }
        return -hp[0][0];
    }
}