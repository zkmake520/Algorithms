import java.lang.*;
import java.util.*;
public class Random5Iterator implements Iterator<Integer>{
	int size;
	int idx = 0;
	Random random;
	public Random5Iterator(int size){
		this.size = size;
		random = new Random();
	}
	@Override
	public boolean hasNext(){
		return idx++ < size;	
	}
	@Override
	public Integer next(){
		Integer num =  new Integer(random.nextInt());

			return num;
	}
	@Override
	public void remove(){

	}
	private class Random5 implements Iterator<Integer>{
		private  Random5Iterator iterator;
		boolean cursor = false;
		Integer num;
		public Random5 (Random5Iterator iterator){
			this.iterator = iterator;
			
		}
		@Override
		public boolean hasNext(){
			cursor = false;
			while(this.iterator.hasNext()){
				Integer num = (Integer) this.iterator.next();
				if(num.intValue()% 5== 0){
					cursor = true;
					this.num = num;
					break;
				}
			}
			return cursor;
		}
		@Override
		public Integer next(){
			return num;
		}
		@Override
		public void remove(){

		}	

	}
	public static void main(String[] args){
		Random5Iterator iterator = new Random5Iterator(10);
		Random5Iterator.Random5 r5 = iterator.new Random5(iterator); 
		while(r5.hasNext()){
			System.out.println((Integer)r5.next());
		}
	}

}