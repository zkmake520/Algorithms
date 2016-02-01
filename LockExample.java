

import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.util.HashMap;
public class LockExample {

	private static final ReentrantReadWriteLock lock = new ReentrantReadWriteLock();
	private static final Object object = new Object();
	private static HashMap<Integer,String> map = new HashMap<>();	
	public static void main(String[] args) throws InterruptedException{
		Thread read1 = new Thread(new Read(),"read1");
		Thread read2 = new Thread(new Read(),"read2");
		Thread read3 = new Thread(new Read(),"read3");
		Thread read4 = new Thread(new Read(),"read4");
		Thread write1 = new Thread(new Write(),"write1");
		Thread write2 = new Thread (new Write(),"write2");
	
		
		write1.start();
		write2.start();
		read1.start();
		read2.start();
		read3.start();
		read4.start();
		read2.join();
		read1.join();	
		write1.join();
		write2.join();
		read3.join();
		read4.join();	
	}
	
	static class Read implements Runnable {

		public void run()  {
			try{
				for(int i = 0; i<= 5; i ++) {
					lock.readLock().lock();
					String val = map.get(i);
					// synchronized(object){
					System.out.println("Before sleep ReadThread:"+Thread.currentThread().getName()+" read Key:"+i+" Message:"+val);
					Thread.currentThread().sleep(200);
					System.out.println("After ReadThread:"+Thread.currentThread().getName()+" read Key:"+i+" Message:"+val);
					lock.readLock().unlock();

				
				}
			}
			catch(Exception e){

			}
		}
	}
	
	static class Write implements Runnable {

		public void run() {
			try{
				for(int i = 0; i<= 5; i ++) {
					lock.writeLock().lock();
					map.put(i,Thread.currentThread().getName()+":"+i);
					System.out.println("WriteThread:"+Thread.currentThread().getName()+" "+"write key:"+i+" val:"+Thread.currentThread().getName()+":"+i);
					lock.writeLock().unlock();
					Thread.currentThread().sleep(100); 
				}
			}
			catch(Exception e){

			}

		}
	}
	
}