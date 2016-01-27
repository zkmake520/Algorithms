public class QuickSort{
	public QuickSort(){
	}
	public void quickSort(int[] array,int s, int e){
		if(s >= e){
			return; 
		}
		int mid = s+(e-s)/2;
		int sp = s;
		int ep = e;
		while(sp <= ep){
			while(array[sp] < array[mid]){
				sp++;
			}
			while(array[ep] > array[mid]){
				ep--;
			}
			if(sp <= ep){
				int tmp = array[ep];
				array[ep] = array[sp];
				array[sp] = tmp; 
				ep--;
				sp++;
			}
		}
		quickSort(array,s,sp);
		quickSort(array,ep,e);
		return;
	}
	

	public static void main(String[] args){
		QuickSort quickSort = new QuickSort();
		int [] array = new int[]{2,3,4,8,1,5,10,12};
		quickSort.quickSort(array,0,array.length-1);
		
		return;
	}

}