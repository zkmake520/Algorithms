public class MaxProducts {
    public int maxProduct(String[] words) {
    	// Arrays.sort(words,new Comparator<String>{
    	// 	@Override
    	// 	public int compare(String a,String b){
    	// 		return Integer.compare(a.length(),b.length());
    	// 	}	
    	// }
    	// );
       	int[] numbers = new int [words.length];
       	for(int i = 0; i < words.length; i++){
       		String word= words[i];
       		int num = 0;
       		for(int j = 0; j < word.length(); j++){
       			int digit = word.charAt(j)-'a';
       			num |= 1 << digit;
       		}
       		numbers[i] = num;
       	}
       	int rst = 0;
       	for(int i = numbers.length -1; i>=0; i--){
       		for(int j = i-1; j >= 0; j--){
       			if(numbers[i] & numbers[j] == 0){
       				rst = Math.max(rst,words[i].length() * words[j].length());
       			}
       		}
       	}
       	return rst;

    }
}