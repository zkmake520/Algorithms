import java.util.*;
public class RangeSSS {

    int [] index;
    int N;
    public RangeSSS(int[] nums) {
        N = nums.length;
        index = new int[N+1];
        for(int i = 0; i < N;i++){
            updateHelp(i,nums[i]);
        }
        for(int i = 0; i < N;i++){
           System.out.print(index[i+1]+ " ");
        }
    }

    void update(int i, int val) {
        if(i != 0){
            int e = getSum(i);
            int s = getSum(i-1);
            System.out.println(e+":"+s);
            updateHelp(i,val-e+s);
        }
        else{
            updateHelp(i,val-getSum(i));
        }
        
    }

    public int sumRange(int i, int j) {
        return getSum(j)-getSum(i-1);
    }
    int getSum(int i){
        i++;
        if(i == 0){
            return 0;
        }
        int sum = 0;
        while(i > 0){
            sum += index[i];
            i -= i&-i;
        }
        return sum;
    }
    void updateHelp(int i,int val){
        i++;
        while(i <= N){
            index[i]+=val;
            i+=i&-i;
        }

    }
    public static void main(String[] args){
        int []a = new int []{1,3,5};
        RangeSSS r= new RangeSSS(a);
        System.out.println(r.sumRange(0,2));
        r.update(1,2);
        System.out.println(r.sumRange(0,2));
    }
}
