import java.util.*;
import java.math.BigInteger;
public class AddtiveNumber {
    public boolean isAdditiveNumber(String num) {
        return help(num,0,0,new ArrayList<BigInteger>());
    }
    boolean help(String str,int index,int last, ArrayList<BigInteger> path){
        if(index == str.length()){
            return isValid(path);
        }
        BigInteger integer = new BigInteger(str.substring(last,index+1));
        path.add(integer);
        boolean res = help(str,index+1,index+1,path);
        path.remove(path.size()-1);
        if(res){
            return true;
        }
        if(!(str.charAt(last)=='0') && index < str.length()-1){
            res = help(str,index+1,last,path);
            if(res){
                return res;
            }
        }
        return res;
        
    }
    boolean isValid(ArrayList<BigInteger> path){
        boolean res = true;
        if(path.size()<3){
            return false;
        }
        BigInteger oneStep,twoStep;
        for(int i = 2;i < path.size();i++){
            oneStep = path.get(i-1);
            twoStep = path.get(i-2);
            if(!path.get(i).equals(oneStep.add(twoStep))){
                return false;
            }
        }
        return res;
        
    }
    public static void main(String[]args){
        AddtiveNumber a = new AddtiveNumber();
        System.out.println(a.isAdditiveNumber("199100199"));
    }
}