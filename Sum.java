public class Sum{
	public int sum(int a,int b){
		int carry = 0;
		while(b!=0){
			carry = ~a &b;
			a = a^b;
			b = carry << 1;
		}
		return a;
	}
	public static void main(String[] args){
		Sum s = new Sum();
		System.out.println(s.sum(123,3233));
	}
}