import java.util.PriorityQueue;
import java.util.Comparator;
public class kthSmallestIn2D{
	public static int kthSmallestElement(int[][] A, int k){
		int m = A.length;
		int n = A[0].length;
		PriorityQueue<MatrixElem> minHeap = new PriorityQueue<>(
			new Comparator<MatrixElem>(){
				@Override
				public int compare(MatrixElem m1, MatrixElem m2){
					return Integer.compare(m1.val,m2.val);
				}
			});
		for(int i = 0 ; i < m;i ++){
			minHeap.add(new MatrixElem(A[i][0],i,0));
		}
		int count = 0;
		MatrixElem kthSmallest = null;
		while(count < k){
			 kthSmallest= minHeap.poll();
			count++;
			if(kthSmallest.col +1 < n){
				minHeap.add(new MatrixElem(A[kthSmallest.row][kthSmallest.col+1],kthSmallest.row,kthSmallest.col+1));
			}
		}
		return kthSmallest.val;

	}
	private static class MatrixElem implements Comparable<MatrixElem>{
		int val;
		int row;
		int col;
		private MatrixElem(int val,int row, int col){
			this.val = val;
			this.row = row;
			this.col = col;
		}
		@Override
		public int compareTo(MatrixElem other){
			return Integer.compare(this.val,other.val);
		}
	}
	public static void main(String[] args){
		int [][] A= new int[][]{{1,2,3,4},{3,4,5,6},{2,3,7,8}};
		System.out.println(kthSmallestIn2D.kthSmallestElement(A,9));
	}

}