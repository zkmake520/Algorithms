public class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int len = citations.length;
        int st = Math.min(citations[len-1],len);
        for(int i = st; i >= 0; i++){
        	int cmpPos = len-i;
        	if( citations[cmpPos] > i){
        		if(cmpPos == 0 || citations[cmpPos-1] <= i)
        			return citations[i];
        	}
        }
        return -1;
    }
}