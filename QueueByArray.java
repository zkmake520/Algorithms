

public class QueueByArray{
	int capacity = 0;
	int [] container = null;
	int s =  0; 
	int e =  0; 
	int size = 0;
	public QueueByArray(int capacity){
		this.container = new int[capacity];
		this.capacity = capacity;
		e = capacity-1;
	}
	public void add(int n){
		if(size == capacity){
			System.out.println("full can't add more elements");
			return ;
		}
		e++;
		e = e % capacity;
		container[e] = n;
		size++;
	}
	public int peek(){
		if(size == 0){
			System.out.println("No elements");
			return -1;
		}
		return container[s];
	}
	public int poll(){
		if(size == 0){
			System.out.println("No elements");
			return -1;
		}
		size--;
		int rst = container[s];
		s++;
		s = s % capacity;
		return rst;
	}
	public int size(){
		return size;
	}
	public static void main(String[] args){
		QueueByArray sol = new QueueByArray(4);
		sol.add(1);
		sol.add(2);
		sol.add(3);
		sol.add(4);
		sol.add(5);
		System.out.println(sol.peek());
		System.out.println(sol.poll());
		System.out.println(sol.poll());
		sol.add(5);
		System.out.println(sol.poll());
		System.out.println(sol.poll());
		System.out.println(sol.poll());
		System.out.println(sol.poll());

	}
}