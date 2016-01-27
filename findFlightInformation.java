public class findFlightInformation{
	public static int getInformation(Stack<Flight> stack){
		HashMap<String,Integer> inDegree = new HashMap<>();
		HashMap<String,Integer> outDegree = new HashMap<>();
		while(!stack.isEmpty()){
			Flight flight = stack.pop();
			String depart = flight.depart;
			String arrival = flight.arrival;
			if(inDegree.containsKey(arrival)){
				inDegree.put(arrival,inDegree.get(arrival)+1);
			}
			else{
				inDegree.put(arrival,1);
			}
			if(outDegree.containsKey(depart)){
				outDegree.put(depart,outDegree.get(depart)+1);
			}
			else{
				outDegree.put(depart,1);
			}
		}
		for(String key:inDegree.keySet()){
			
		}
	}
}