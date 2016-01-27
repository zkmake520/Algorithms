public class FindMedian{
	public int findIndex(int[] nums,int k){
		if(nums.length == 0){
			return -1;
		}
		if(nums[nums.length-1] < k){
			return -1;
		}
		return binarySearch(nums,0,nums.length, k);
	}
	private int binarySearch(int[] nums,int l,int r,int k){
		int mid = l+(r-l)/2;
		int num = nums[mid];
		if(num < k && nums[mid+1] >= k ){
			return mid+1;
		}
		if(num >= k && ((mid-1 >=l && nums[mid-1] < k) || mid-1 <l)){
			return mid;
		}
		if(num >= k){
			return binarySearch(nums,l,mid,k); 
		}
		return binarySearch(nums,mid+1,r,k);
		
	}
	public static void main(String[] args){
		FindMedian sol = new FindMedian();
		System.out.println(sol.findIndex(new int[]{1,1,3,3,5,6},4) == 4);
		System.out.println(sol.findIndex(new int[]{1,1,3,3,5,6},3) == 2) ;
		System.out.println(sol.findIndex(new int[]{2,3},1) == 0) ;
		System.out.println(sol.findIndex(new int[]{2,3},4) == -1) ;
		System.out.println(sol.findIndex(new int[]{2,3,4,5,6},6) == 4) ;
		System.out.println(sol.findIndex(new int[]{},1) == -1) ;
		System.out.println(sol.findIndex(new int[]{2,2,2,2},2) == 0) ;
		System.out.println(sol.findIndex(new int[]{2,2,3},3) == 2) ;
	}

}