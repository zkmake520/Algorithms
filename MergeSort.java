public class MergeSort{
	public static void mergeSort(int [] A,int s, int e){
		if(s >= e){
			return;
		}
		int mid = s +(e-s)/2;
		mergeSort(A,s,mid);
		mergeSort(A,mid+1,e);
		merge(A,s,mid,e);
	}
	private static void merge(int [] A, int s, int mid, int e){
		int i = s;
		int j = mid+1;
		int [] tmp = new int[e-s+1];
		int count = 0;
		while(i <=mid && j <= e){
			if(A[i] < A[j]){
				tmp[count++] = A[i];
				i++;
			}
			else{
				tmp[count++] = A[j];
				j++;
			}
		}
		while(i <= mid){
			tmp[count++]= A[i++];
		}
		while(j <= e){
			tmp[count++] = A[j++];
		}
		for(int num:tmp){
			A[s++] = num;
		}
		return;
	} 
	public static void main(String[] args){
		int[] A =  new int[]{2,3,4,1,2,3,1,44,12,322};
		MergeSort.mergeSort(A,0,A.length-1);
		for(int num : A){
			System.out.println(num+" ");
		}
	}
}