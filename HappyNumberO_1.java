public class HappyNumberO_1 {
   public boolean isHappy(int n) {
    	int fast = n, slow = n;
        do{
    		slow = getNewNum(slow);
    		fast = getNewNum(fast);
    		fast = getNewNum(fast);
    	} while(fast != slow);
        return slow==1?true:false;
    }
    int getNewNum(int n){
        int sum = 0;
        while(n != 0){
            int digit =n % 10;
            n = n/10;
            sum += digit *digit;
        }
        return sum;
    }

}

