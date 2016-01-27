import java.lang.*;
import java.util.*;
public class TimeStamp{
	class QueueIterator implements Iterator{
		
		private int size = 0;
		private int idx = 0;
		private double cur = 0;
		private double incre = 0;
		QueueIterator(int size,double incre){
			this.size = size;
			this.incre = incre;
		}
		@Override 
		public boolean hasNext(){
			return idx < size;
		}
		@Override 
		public void remove(){

		}
		@Override 
		public Object next(){
			cur += this.incre;
			idx++;
			return cur;
		}
	}
	private LinkedList<Double> l1;
	private LinkedList<Double> l2;

	public TimeStamp(LinkedList<Double> l1, LinkedList<Double> l2){
		this.l1 = l1;
		this.l2 = l2;
	}
	public void FindTimeStampPairs(QueueIterator q1,QueueIterator q2){
		int turn = 1;
		boolean quit1 = false;
		boolean quit2 = false;
		while(true){
			if(turn %2 == 1 && quit1 == false){
				turn++;
				if(q1.hasNext()){
					double num = (Double)q1.next();
					l1.add(num);
					while(!l2.isEmpty() && Math.abs(num-l2.peek()) > 1){
						l2.poll();
					}
					for(double n2: l2){
						System.out.println(num+":"+n2);
					}
				}
				else{
					quit1 = true;
				}
				
			}
			else if(turn %2 == 0 && quit2 == false){
				turn++;
				if(q2.hasNext()){
					double num = (Double)q2.next();
					l2.add(num);
					while(!l1.isEmpty() && Math.abs(num-l1.peek()) > 1){
						l1.poll();
					}
					for(double n1: l1){
						System.out.println(num+":"+n1);
					}
				}
				else{
					quit2 = true;
				}
			}
			if(quit1 & quit2){
				break;
			}
		}
	}


	public QueueIterator getQueue(int size,double incre){
		return new QueueIterator(size,incre);
	}
	public static void main(String[] args){

		TimeStamp timeStamp = new TimeStamp(new LinkedList<Double>(), new LinkedList<Double>());
		TimeStamp.QueueIterator q1 = timeStamp.getQueue(6,0.3);	
		TimeStamp.QueueIterator q2 = timeStamp.getQueue(6,0.5);	
		timeStamp.FindTimeStampPairs(q1,q2);
	}

}