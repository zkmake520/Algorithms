public class StrictlyIncreasingSubArray{
	int countIncreasing(int[] A){
		int cnt = 0;
		int continuous = 1;
		for(int i = 0;i < A.length - 1; i++){
			if(A[i+1] > A[i]){
				continuous++;
			}
			else{
				last = a;
				cnt += (continuous) * (continuous-1)/2; 
				continuous = 1;
			}
		}
		cnt += (continuous) * (continuous-1)/2; 
		return cnt;
	}
}