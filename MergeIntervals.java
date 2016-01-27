/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        Collections.sort(intervals,new Compartor<Interval>(){
  		  	@Override
  		  	public int compare(Interval i1, Interval i2){
  		  		return Integer.compare(i1.start,i2.start);
  		  	}
        });
        List<Interval> res = new ArrayList<Interval>();
        if(intervals.size() == 0){
        	return res;
        }
        Interval cur = res.get(0); 
        for(int i =1 ;i <intervals.size();i++){
        	Interval i = intervals.get(i);
        	if(i.end >= cur.start){
        		cur.end = i.end;	
        	}
        	else{
        		res.add(cur);
        		cur = i;
        	}
        }
        return res;

    }
}