import java.util.HashSet;
public class LongestIncreasingSubArray{
	HashSet<Integer> set = new HashSet<>();
	/*
		the general idea is that, we need to find all the smallest numbers for each 
		sequence, and count the length from this smallest number, and for all other numbers if it is not smallest
		(checked by using hashset has(num-1) or not) we can skip it directly!!!
		Time:O(2*n)
	 */
	public int getLongestSubArray(int[] A){
		int max = 0;
		for(int num:A){
			set.add(num);
		}
		for(int num:A){
			if(!set.contains(num-1)){
				//this item is the smallest starting point for a sequence
				int cur = 1;
				num++;
				while(set.contains(num++)){
					cur++;
				}
				max = cur>max?cur:max;
			}
		}
		return max;
	}
	public static void main(String[] args){
		LongestIncreasingSubArray sol = new LongestIncreasingSubArray();
		System.out.println(sol.getLongestSubArray(new int[]{1,9,10,8,11,2,4,5,7,6,12}));
	}
}