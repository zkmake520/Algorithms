public class bulbs {
    public int bulbSwitch(int n) {
        int rst = 0;
        for(int i = 1; i <= n; i++){
            int divisors = getDivisors(i);
            
            if(divisors % 2 != 0){
                rst++;
            }
        }
        return rst;
    }
    int getDivisors(int num){
        int count = 0;
        int upBounds = num/2;
        int incre = 1;
        if(num %2 !=0){
            //only need to consider the odd number
            incre = 2;
        }
        for(int i = 1; i <= upBounds; i+= incre){
            if(num % i ==0){
                count++;
            }
        }
        return count;
    }
    public static void main(String[] args){
        bulbs sol = new bulbs();
        System.out.println(sol.bulbSwitch(99999));
    }
}