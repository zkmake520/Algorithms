import java.util.*;
public class RemoveSubtree{
	class Node{
		int parent;
		Node(int parent){
			this.parent = parent;
		}
	}
	Node[] tree;
	int[] father;
	public RemoveSubtree(){
		Node t1 = new Node(3);
		Node t2 = new Node(3);
		Node t3 = new Node(4);
		Node t4 = new Node(6);
		Node t5 = new Node(6);
		Node t6 = new Node(-1);
		tree = new Node[]{t1,t2,t3,t4,t5,t6};
		int size = tree.length;
		father = new int[size];
	}

	public void removeIndex(int index){
		for(int i = 1; i <= tree.length; i++){
			father[i-1] = helper(i,index);
			if(father[i-1] == index){
				System.out.println(i);
			}	
		}

	}

	private int helper(int i,int index){
		if(father[i-1] != 0){
			return father[i-1];
		}
		Node node = tree[i-1];
		if(node.parent == -1 || i == index){
			return i; 
		}
		father[i-1] =  helper(node.parent,index);
		return father[i-1];
	}
	public static void main(String[] args){

		RemoveSubtree removeSubtree = new RemoveSubtree();
		Scanner scanner = new Scanner(System.in);
		int index = scanner.nextInt();
		removeSubtree.removeIndex(index);
	}


}