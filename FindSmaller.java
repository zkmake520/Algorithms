import java.util.*;
public class FindSmaller {
    class Node {
        Node left, right;
        int val, sum, dup = 1;
        public Node(int v, int s) {
            val = v;
            sum = s;
        }
    }
    public List<Integer> countSmaller(int[] nums) {
        Node root = null;
        Integer[] rst = new Integer[nums.length];
        for(int i = nums.length-1;i >= 0; i--){
            root = insertNode(nums[i],root,0,rst,i);
            
        }
        return Arrays.asList(rst);
    }
    public Node insertNode(int val, Node root,int smaller,Integer[]rst,int i){
        if(root == null){
            root = new Node(val,0);
            rst[i] = smaller; 
        }
        else{
            if(root.val == val){
                root.dup++; 
                rst[i] = smaller+root.sum;
            }
            if(root.val > val){
                root.left = insertNode(val,root.left,smaller,rst,i);
                root.sum++;
            } 
            if(root.val < val){
                root.right = insertNode(val,root.right,smaller+root.dup+root.sum,rst,i);
            }
           
        }
        return root;

    } 
    public static void main(String[] args){
        FindSmaller sol = new FindSmaller();
        List<Integer> rst = sol.countSmaller(new int[]{5,4,2,3,6,1,2});
        for(int num:rst){
            System.out.println(num);
        }
    }
}