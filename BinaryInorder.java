import java.util.*;
class Node {
 
		int data;
	    Node left, right;
		 
	    public Node(int item) {
	        data = item;
	        left = right = null;
	    }
	}
public class BinaryInorder{
	 Node root;
	public void inOrder(){
		Stack<Node> stack = new Stack<>();
		Node tmp = root;
		while(tmp!= null){
			stack.push(tmp);
			tmp = tmp.left;
		}
		while(!stack.isEmpty()){
			tmp = stack.pop();
			System.out.print(tmp.data+ " ");
			if(tmp.right != null){
				tmp = tmp.right;
				while(tmp != null){
					stack.push(tmp);
					tmp = tmp.left;
				}
			}
		}

	}
	 public static void main(String args[]) {
         
        /* creating a binary tree and entering 
         the nodes */
        BinaryInorder tree = new BinaryInorder();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.inOrder();
    }
}