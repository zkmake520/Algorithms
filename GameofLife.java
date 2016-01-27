import java.lang.*;
public class GameofLife {
	Object object = new Object();
    public void gameOfLife(int[][] board,int row) {
    	int m = board.length;
    	if(m == 0){
    		return;
    	}
    	int n = board[0].length;
    	if(n == 0){
    		return;
    	}
    	int i = row;
    	// synchronized(object){
    	for(int j = 0; j < n; j++){
    		int live = 0;
    		System.out.println();
    		for(int p = Math.max(i - 1, 0); p <= Math.min(i + 1, m - 1); p++) {
    			for(int q = Math.max(j - 1, 0); q <= Math.min(j + 1, n - 1); q++) {
        			live += board[p][q] & 1;
    			}
			}
			live -= board[i][j] &1;

			System.out.print("i:"+i+" j:"+j+" live:"+live+" board:"+board[i][j]);
			
    		if(board[i][j]==1 && (live < 2||live > 3)){
    			board[i][j] = 3;
    		}
    		else if(board[i][j] == 0 && live == 3){
    			board[i][j] = 2;
    		}
    	}
    	
    	// }
    }
    class Job implements Runnable{
    	int [][] board;
    	int row;
    	public Job(int[][]board,int row){
    		this.board = board;
    		this.row = row;
    	}
    	@Override
    	public void run(){
    		gameOfLife(board,row);
    	}
    }
    public static void main(String[] args){
    	GameofLife gameOfLife = new GameofLife();
    	int[][] board = new int[][]{{1,0,1},{1,1,0},{1,1,0}};
    	GameofLife.Job j1 = gameOfLife.new Job(board,0);
    	GameofLife.Job j2 = gameOfLife.new Job(board,1);
    	GameofLife.Job j3 = gameOfLife.new Job(board,2);
    	Thread t1 = new Thread(j1,"t1");
    	Thread t2 = new Thread(j2,"t2");
    	Thread t3 = new Thread(j3,"t3");
    	t1.start();
    	t2.start();
    	t3.start();
    	try{
	    	t1.join();
	    	t2.join();
	    	t3.join();
	    } catch(Exception e){

	    }
	    
    	for(int i = 0 ;i < 3 ;i++){
    		System.out.println();
    		for(int j = 0; j < 3;j++){
    			if(board[i][j] == 2){
    				board[i][j] = 1;
	    		}
	    		if(board[i][j] == 3){
	    			board[i][j] = 0;
	    		}
    			System.out.print(board[i][j]+" ");
    		}
    		
    	}
    }
}