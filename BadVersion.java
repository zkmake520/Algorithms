public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
   		int l = 1;
   		int r = n;
   		int mid;
   		while(l <r){
   			mid = l+(r-l)/2;
   			if(isBadVersion(mid)){
   				r = mid;
   			}
   			else{
   				l = mid+1;	
   			}
   		}   
   		return l;
    }
}