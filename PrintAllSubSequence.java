
public class PrintAllSubSequence{
	public static void printAllSubSequence(int [] A){
		int size = 1 << A.length;
		for(int i = 1; i < size; i++){
			for(int j = 0; j < A.length; j++){
				if((i & (1 << j)) != 0){
					System.out.print(A[j]+" ");
				}
			}
			System.out.println();
		}
	}
	public static void main(String[] args){
		printAllSubSequence(new int[]{1,2,3,4});
	}
}