public class AbsentNumbers{
	public static void main(String[] args){
		int[] A = new int[]{1,3,2,5};
		int[] B = getAbsentNumbers(A);
		for(int num:B){
			System.out.println(num);
		}

	}
	public static int[] getAbsentNumbers(int[] A){
		int len  = A.length;
		int [] res = new int[len];
		//check 0~n-1
		int count = 0;
		for(int i = 0;i < len; i++){
			Collections.sort(A);
		}
		for(int i = 0;i < len; i++){
			if(A[i] != i){
				res[count++] = i;
			}
		}

		for(int num:res){
			System.out.println(num);
		}
		//check n~2*n-1
		for(int i = 0;i < len; i ++){
			if( len <= A[i]){
				int tmp = A[i];
				A[i] = A[tmp-len];
				A[tmp-len] = tmp;
			}
		}
		for(int i = 0; i< len; i++){
			if( A[i]-len != i){
				res[count++] = i+len;
			}
		}
		return res;
	}
}