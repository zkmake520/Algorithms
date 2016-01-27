public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        //four different types
        int s = newInterval.start;
        int e = newInterval.end;
        int idx = binarySearch(intervals,s,1);
        int endIdx = binarySearch(intervals,e,1);
        List<Integer> res = new ArrayList<Integer>();
        findAllInside(intervals,s,e,res);
        Interval interval = new Interval();
        interval.start =s;
        interval.end =e;
       	if(idx != -1){
       		interval.start = intervals.get(idx).start;
       	}

       	if(endInde != -1){
       		interval.end = intervals.get(endIdx).end;
       	}
       	if(!res.isEmpty()){
       		
       	}

    }
    int binarySearch(List<Interval> intervals, int target, int searchType){
    	int l = 0;
    	int r = intervals.size()-1;
    	while(l <= r){
    		int mid = l+ (r-l)/2;
    		int midS = intervals.get(mid).start;
    		int midE= intervals.get(mid).end;
    		if(midS <= target && midE >= target){
    			return mid;
    		}
    		else{
    			if(midS > target){
    				r = mid -1;
    			}
    			if(midE < target){
    				l = mid +1;
    			}
    		}
    	}
    	if(searchType == 1){
    		return -1;
    	}
    }
    void findAllInside(List<Integer> intervals, int s, int e, int l,int r,List<Integer> res){
    	if(l > r){
    		return ;
    	}
    	int mid = l+(r-l)/2;
    	int midS = intervals.get(mid).start;
    	int midE = intervals.get(mid).end;
    	if(midS >= s && midE <= e){
    		res.add(mid);
    		findAllInside(intervals,s,e,l,mid-1,res);
    		findAllInside(intervals,s,e,mid+1,e,res);
    	}
    	if(midS > e){
    		findAllInside(intervals,s,e,l,mid-1,res);
    	}
    	if(midE < s){
    		findAllInside(intervals,s,e,mid+1,e,res);
    	}
    	return ;

    }
}