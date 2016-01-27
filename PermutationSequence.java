public class Solution {
    public String getPermutation(int n, int k) {
    	int[] permutationCount = new int[10];
    	permutationCount[1] = 1;
        for(int i =2;i <= n;i++){
        	permutationCount[i] = permutationCount[i-1]*i;
        }
        String res ="";
        get(permutationCount,n,k,res);
        return res;
    }
    void get(int[] permutationCount,int n, int k,String res){
    	int i;
    	for( i = 1 ; i <= n; i++){
    		if(permutationCount[n-1]*i >=k){
    			break;
    		}
    	}
    	res += (i+'0');
    	get(permutationCount,n-1,k-(permutationCount[n-1]*(i-1)),res);
    	return;
    } 
}