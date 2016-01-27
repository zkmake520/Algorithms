import java.lang.*;
import java.util.*;
public class TimeStampThread{
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
	LinkedList<Double> l1;
	LinkedList<Double> l2;
 	private static Object sharedLock = new Object();
	public TimeStampThread(LinkedList<Double> l1, LinkedList<Double> l2){
		this.l1 = l1;
		this.l2 = l2;
	}
	class Job implements Runnable{
		private QueueIterator q;
		private LinkedList<Double> host;
		private LinkedList<Double> client;
		Job (QueueIterator q, LinkedList<Double> host,LinkedList<Double> client){
			this.q  = q;
			this.host = host;
			this.client = client;
		}
		@Override
		public void run(){
			
				while(q.hasNext()){
					double timeStamp = (Double)q.next();
				//add lock
				synchronized(sharedLock){
					host.add(timeStamp);	
				
					while(!client.isEmpty() && Math.abs(timeStamp-client.peek()) > 1){
						client.pop();
					}
					for(double num: client){
						System.out.println("host:"+timeStamp+" "+"client:"+num);
					}
				}
			}
		}
	}


	public QueueIterator getQueue(int size,double incre){
		return new QueueIterator(size,incre);
	}
	public static void main(String[] args){

		TimeStampThread timeStamp = new TimeStampThread(new LinkedList<Double>(), new LinkedList<Double>());
		TimeStampThread.QueueIterator q1 = timeStamp.getQueue(6,0.3);	
		TimeStampThread.QueueIterator q2 = timeStamp.getQueue(6,0.5);	
		TimeStampThread.Job job1 = timeStamp.new Job(q1,timeStamp.l1,timeStamp.l2);
		TimeStampThread.Job job2 = timeStamp.new Job(q2,timeStamp.l2,timeStamp.l1);
		Thread thread1 = new Thread(job1,"job1");
		Thread thread2 = new Thread(job2,"job2");
		thread1.start();
		thread2.start();
		try{
			thread1.join();
			thread2.join();
		}catch(Exception e){

		}
	}

}