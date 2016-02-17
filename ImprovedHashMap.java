import java.util.*;
public class ImprovedHashMap{
	// traditional hashmap has O(n) clear time and O(hash size) iteration time
	// here by using more storage space , we reduce the clear time to O(1) and iteration time to O(number of elements)
	// And we assume that the hashmap is big enough, thus there is no collision
	int globalTimeStamp = 0;
	class Entry {
		int value;
		int timestamp;
		int index;
		Entry(int value, int timestamp, int index){
			this.value = value;
			this.timestamp = timestamp;
			this.index = index;
		}
	}
	HashMap<Integer,Entry> container =  new HashMap<>();
	int size = 0;
	int[] keys;   

	public ImprovedHashMap(int capacity){
		keys = new int[capacity]; 
	}
	public int size(){
		return size;
	}
	public int get(int key){
		if(container.containsKey(key)){
			int val = container.get(key).value;
			int timestamp = container.get(key).timestamp;
			if(timestamp < globalTimeStamp){
				//means that this k-v has out of date or has been cleared;
				container.remove(key);
				return -1;
			}
			return val;
		}
		return -1;
		//return the value of key
	}
	public boolean put(int key, int value){
		int index = 0;
		if(!container.containsKey(key) || container.get(key).timestamp < globalTimeStamp){
			index = size;
			keys[size++] = key;
		}
		else{
			index = container.get(key).index;
		}
		Entry entry = new Entry(value,globalTimeStamp,index);
		container.put(key,entry);
		return true;
		//put new k-v pair
	}
	public boolean delete(int key){
		if(container.containsKey(key) && container.get(key).timestamp >= globalTimeStamp){
			Entry entry = container.get(key);
			int index = entry.index;
			container.remove(key);
			keys[index] = keys[--size];
			return true;
		}
		else if(container.containsKey(key)){
			container.remove(key);
		}
		return false;
		//delete one key
	}
	class MapIterator implements Iterator<Integer>{
		int idx = 0;
		@Override
		public 	Integer next(){
			return new Integer(keys[idx++]);
		}
		@Override
		public boolean hasNext(){
			return idx < size;	
		}
		@Override
		public void remove(){
			return ;
		}

	}
	public Iterator iterator(){
		// return a iterator
		return new MapIterator();

	}
	public void clear(){
		globalTimeStamp++;
		size = 0;
	}
	public static void assertEqual(boolean expect,boolean actual,int num){
		System.out.println((expect==actual)+" test "+num);
	}
	public static void assertEqual(int expect,int actual,int num){
		System.out.println((expect==actual)+" test "+num);
	}
	public static void main(String[] args){
		ImprovedHashMap map = new ImprovedHashMap(16);
		assertEqual(0,map.size(),1);
		assertEqual(true,map.put(0,0),2);
		assertEqual(1,map.size(),3);
		assertEqual(0,map.get(0),4);
		assertEqual(true,map.put(0,2),5);
		assertEqual(2,map.get(0),6);
		assertEqual(-1,map.get(1),7);
		assertEqual(true,map.put(1,1),7);
		map.clear();
		assertEqual(0,map.size(),8);
		assertEqual(-1,map.get(0),9);
		assertEqual(true,map.put(1,1),10);
		assertEqual(1,map.get(1),11);
		assertEqual(1,map.size(),12);
		map.clear();
		assertEqual(false,map.delete(1),13);
		map.put(2,2);
		map.put(3,3);
		map.put(4,4);
		Iterator iter = map.iterator();
		while(iter.hasNext()){
			Integer key = (Integer)iter.next();
			int k = key.intValue();
			System.out.println(k+":"+map.get(k));
		}
	} 
}