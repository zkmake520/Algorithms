import java.util.*;
public class AlienDictionary{
	public String getOrdering(String[] words){
		HashMap<Character,HashSet<Character>> outLink = new HashMap<Character,HashSet<Character>>();
		HashMap<Character,HashSet<Character>> inDegree = new HashMap<Character,HashSet<Character>>();
		Set<Character> allChars = new HashSet<Character>();
		for(int i = 0; i < words.length; i ++){
			for(int j = 0; j < words[i].length(); j++){
				char c = words[i].charAt(j);
				allChars.add(c);
				HashSet<Character> list = new HashSet<>();
				for(int k= j+1; k <words[i].length();k++){
					char c2 = words[i].charAt(k);
					if(c == c2){
						continue;
					}
					allChars.add(c2);
					list.add(c2);
					if(inDegree.containsKey(c2)){
						HashSet<Character> set = inDegree.get(c2);
						set.add(c);
						inDegree.put(c2,set);
					}
					else{
						HashSet<Character> preRequire = new HashSet<>();
						preRequire.add(c);
						inDegree.put(c2,preRequire);
					}
				}
				if(outLink.containsKey(c)){
					HashSet<Character> set = outLink.get(c);
					set.addAll(list);
					outLink.put(c,set);
				}
				else{
					outLink.put(c,list);
				}

			}
		} 
		//hashmap .
		//keySet and itemSet
		List<Character> startChars = new ArrayList<Character>();
		for(char c: allChars){
			if(!inDegree.containsKey(c)){
				startChars.add(c);
			}
		}

		LinkedList<Character > queue = new LinkedList<Character>();
		for(int i = 0; i < startChars.size(); i++){
			queue.add(startChars.get(i));
		}
		StringBuilder sb = new StringBuilder();
		while(!queue.isEmpty()){
			char c = queue.poll();
			sb.append(c);
			if(outLink.containsKey(c)){
				Set<Character> pointTo = outLink.get(c);
				for(char point: pointTo){
					inDegree.get(point).remove(c);
					if(inDegree.get(point).isEmpty()){
						queue.add(point);
					}
				}
			}	
		}
		return sb.toString();

	}
	public static void main(String[] args){
		AlienDictionary alienDictionary = new AlienDictionary();
		String[] test = new String[] {"wrt","wrf","er","ett","rftt"};
		System.out.println(alienDictionary.getOrdering(test));
	}
}