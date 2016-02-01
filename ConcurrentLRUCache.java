import java.util.*;
public class ConcurrentLRUCache<K,V>{
	private ConcurrentHashMap<K,V> map;
	private ConcurrentLinkedQueue<K> list;
	private capacity;
	public ConcurrentLRUCache(int capacity){
		this.capacity = capacity;
		map = new ConcurrentHashMap<K,V>();
		list = new ConcurrentLinkedQueue<>();
	}

	public V get(K k){
		V v = null;
		if(map.containsKey(k)){
			v  = map.get(k);
			list.remove(k);
			list.addLast(k);
		}
		return v;
	}

	public void set(K k, V v){
		if(map.size() == capacity){
			if(map.containsKey(k)){
				map.put(k,v);
				list.remove(k);
				list.addLast(k);
			}
			else{
					
			}
		}
		else{
			map.put(k,v);
			list.remove(k);
			list.addLast(k);
		}
	}


}