import java.util.*;
public class ValidString{
	public String getValidFormat(String s){
		HashMap<Character,Integer> map = new HashMap<Character,Integer>();
		for(int i = 0;i < s.length(); i++){
			char c = s.charAt(i);
			if(map.containsKey(c)){
				map.put(c,map.get(c)+1);	
			}	
			else{
				map.put(c,1);
			}
		}
		StringBuilder sb = new StringBuilder();
		PriorityQueue<Character> heap = new PriorityQueue<>();
		for(char c : map.keySet()){
			heap.add(c);
		}		
		char leftOneChar = '\0';
		while(!heap.isEmpty()){
			char c1 = heap.poll();
			if(heap.isEmpty()){
				leftOneChar = c1;
				break;
			}
			char c2 = heap.poll();
			sb.append(c1);
			sb.append(c2);
			int count1 = map.get(c1);
			int count2 = map.get(c2);
			if(count1 > 1){
				map.put(c1,count1 -1);
				heap.add(c1);
			}
			if(count2 > 1){
				map.put(c2,count2 -1);
				heap.add(c2);
			}
		}
		if(leftOneChar!='\0'){
			int count = map.get(leftOneChar);
			int j = 0 ;
			for(int i = 0 ; i < count; i++,j = j+2){
				sb.insert(j,leftOneChar);
			}
		}
		return sb.toString();	
	}
	public static void main(String[] args){
		ValidString vs = new ValidString();
		System.out.println(vs.getValidFormat("abffffcccdaaff"));		
	}
}
