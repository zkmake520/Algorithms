import java.util.*;
class Job{
	int s;
	int e;
	int p;
	Job(int s,int e, int p){
		this.s = s;
		this.e = e;
		this.p = p;
	}
}
public class WeightedJobSchedule{

	int binarySearch(Job j, Job[] A,int l, int h){
		while(l <= h){
			int mid = l + (h-l)/2;
			if(A[mid].e <= j.s){
				if(mid+1 < A.length && A[mid+1].e <= j.s){
					l = mid +1;
				}
				else{
					return mid;
				}
			}
			else{
				h = mid-1;
			}
		}
		return -1;
	}

	public int scheduleProfit(Job [] A){
		int[] profit = new int[A.length+1];
		Arrays.sort(A,new JobComparator());
		profit[0] = 0;
		for(int i = 0; i < A.length; i++){
			//pick this job
			int p = A[i].p;
			int idx = binarySearch(A[i],A,0,i-1);
			if(idx != -1){
				p += profit[idx+1];
			}
			profit[i+1] = Math.max(p,profit[i]);
		}
		return profit[A.length];
	}
	class JobComparator implements Comparator<Job>{
		@Override
		public int compare(Job j1, Job j2){
			return j1.e < j2.e ? -1 : j1.e == j2.e ? 0 : 1;
		}
	}
	 // Driver method to test above
    public static void main(String[] args)
    {
        Job jobs[] = {new Job(1, 2, 50), new Job(3, 5, 20),
                      new Job(6, 19, 100), new Job(2, 100, 200)};
 
        System.out.println("Optimal profit is " + new WeightedJobSchedule().scheduleProfit(jobs));
    }
}