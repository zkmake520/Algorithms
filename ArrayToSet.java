import org.junit.Test;
import static org.junit.Assert.assertEquals;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;
public class ArrayToSet<E>{
	private int size;
	E [] array;
	private int capacity;
	private static int defaultCapacity = 20;
	@SuppressWarnings("unchecked")
	public ArrayToSet(int capacity){
		try{
			if(capacity < 0){
				throw new Exception ("fff");
			}
			array = (E[])new Object[capacity];
			this.capacity = capacity;
		}catch(Exception e){
			System.out.println(e);
		}
	}
	public ArrayToSet(){
		this(defaultCapacity);
	}
	public ArrayToSet(E [] array){
		this(defaultCapacity,array);
	}
	public ArrayToSet(int capacity,E [] array){  //if this array contains duplicate?
		try{
			if(capacity < 0){
				throw new Exception("fff");
			}
			this.array = array;
		
			if(array == null){
				this.size = 0;
				this.capacity = capacity;
			}
			else{
				this.size = array.length;
				this.capacity = capacity;
			}
		}catch(Exception e){	
			System.out.println(e);

		}
		
	}
	boolean isEmpty(){
		return size == 0?true:false;
	}
	@SuppressWarnings("unchecked")
	boolean contains(Object o){
		if(array == null){
			return false;
		}
		if(o == null){
			for(int i = 0;i < size; i++){
				if(array[i] == null){
					return true;
				}
			}
		}
		else{
			for(int i = 0; i < size; i++){
				if(array[i].equals((E)o)){
					return true;
				}
			}
		}
		return false;
	}
	boolean add(E e){
		if(array == null){
			return false;
		}
		if(contains(e)){
			return false;
		}
		else{
			if(size == capacity){
				return false;
			}
			array[size++] = e;
			return true;
		}
	}
	boolean remove(Object e){
		if(array == null){
			return false;
		}
		if(e == null){
			for(int i = 0; i < size; i++){
				if(array[i] == null){
					array[i] = array[size-1];
					size--;
					return true;
				}
			}
		}
		else{
			for(int i = 0;i < size; i++){
				if (e.equals(array[i])){
					array[i] = array[size-1];
					size--;
					return true;
				}
			}
		}
		return false;
	}
	int size(){
		return size;
	}
	public static void main(String[] args){
		Result result = JUnitCore.runClasses(UnitTest.class);
	    for(Failure failure : result.getFailures()) {
	        System.out.println(failure.toString());
	    }
	    // System.out.println(result.wasSuccessful());
	}

	

}