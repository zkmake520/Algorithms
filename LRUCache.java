import java.util.LinkedHashMap;
public class LRUCache {
    
    CacheMap<Integer, Integer> map;
    int capacity = 0;
    public LRUCache(int capacity) {
        map = new CacheMap<Integer,Integer>(capacity,(float)0.75,true);
        this.capacity = capacity;
    }
    
    public int get(int key) {
        int rst = -1;
        if(map.containsKey(key)){
            rst = map.get(key);
        }   
        return rst;
    }
    
    public void set(int key, int value) {
        map.put(key,value);
    }
    private class CacheMap <K,V> extends LinkedHashMap<K,V>{
        CacheMap (int capacity, float loadFactor, boolean accessOrder){
            super(capacity,loadFactor,accessOrder);
        }
        @Override
        protected boolean removeEldestEntry(Map.Entry<K,V> eldest) {
            return size() > capacity;
        }
    }
}