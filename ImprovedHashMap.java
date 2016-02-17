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
	public int get(int key){
		if(container.containsKey(key)){
			int val = container.get(key).value;
			int timestamp = container.get(key).timestamp;
			if(timestamp < globalTimeStamp){
				//means that this k-v has out of date or has been cleared;
				return -1;
			}
			return val;
		}
		return -1;
		//return the value of key
	}
	public boolean put(int key, int value){
		int index = 0;
		if(!container.containsKey(key)){
			index = size;
			keys[size++] = key;
		}
		else{
			index = container.get(key).index;
		}
		Entry entry = new Entry(value,globalTimeStamp,index);
		boolean success = container.put(key,entry);
		return success;
		//put new k-v pair
	}
	public boolean delete(int key){
		if(container.containsKey(key)){

		}
		return false;
		//delete one key
	}
	public Iterator iterator(){
		// return a iterator
	}
	public void clear(){

	}
	public static void main(String[] args){

	} 
}