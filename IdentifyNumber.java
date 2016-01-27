import java.util.*;
public class IdentifyNumber{
	
	public boolean identifyPowerOf4(int n){
		/**
		 * 
		 */
		return n!=0 && ((n&(n-1)) ==0?true:false) &&  (n&0x55555555)!=0;
	}
	public static void main(String[] args){
		IdentifyNumber indentifyNumber = new IdentifyNumber();
		System.out.println("choose base number:");
		Scanner scanner = new Scanner(System.in);
		System.out.println(indentifyNumber.identifyPowerOf4(scanner.nextInt()));

	}

}