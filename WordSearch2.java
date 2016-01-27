import java.util.*;

/**
 * Created by zkwangchao on 15/8/26.
 */

public class Solution {
    class TrieNode{
        boolean isLeaf=false;
        HashMap<Character,TrieNode> subNodes = new HashMap<Character,TrieNode>();

    }
    TrieNode root = new TrieNode();
    public List<String> findWords(char[][] board, String[] words) {
        for(int i =0;i < words.length;i++){
            insert(words[i]);
        }
        Set<String> res = new HashSet<String>();
        List<String> ans = new ArrayList<String>();
        if(board.length == 0){
            return ans;
        }
        if(board[0].length == 0){
            return ans;
        }
        for(int i = 0; i < board.length;i++){
            for(int j = 0;j < board[0].length; j ++){
                search(i,j,board,"",res,new HashSet<Integer>(),root);

            }
        }
        ans = new ArrayList<>(res);
        return ans;
    }
    public void insert(String word) {
        HashMap<Character, TrieNode> subNodes = root.subNodes;
        for(int i =0;i < word.length(); i++){
            char c = word.charAt(i);
            TrieNode t;
            if(subNodes.containsKey(c)){
                t = subNodes.get(c);
            } else{
                t = new TrieNode();
                subNodes.put(c,t);
            }
            subNodes = t.subNodes;
            if(i == word.length() - 1){
                t.isLeaf = true;
            }
        }
    }
    public void search(int r, int c, char[][] board,String word,Set<String> res, Set<Integer> path,TrieNode root){
        if(r < 0 || r >= board.length || c < 0 || c>= board[0].length || path.contains(r*board[0].length+c)){
            return;
        }
        if(!root.subNodes.containsKey(board[r][c])){
            return;
        }
        TrieNode node = root.subNodes.get(board[r][c]);
        if(node.isLeaf){
            res.add(word+board[r][c]);
        }
        path.add(r * board[0].length + c);
        //here no need to check if r-1<0.or balbal casue we can put all checkings on the beginning of this local search like
        //whether it is out of range or this position has been used or something. which can make the program more beautiful
        search(r - 1, c, board, word + board[r][c], res, path, node);
        search(r+1,c,board,word+board[r][c],res,path,node);
        search(r,c-1,board,word+board[r][c],res,path,node);
        search(r, c + 1, board, word + board[r][c], res, path, node);
        path.remove(r*board[0].length+c);
        return;

    }
    public  static void main(String[] args){
        String [] words = new String[]{"acdb"};
        char [][] board = new char[][]{{'a','b'},{'c','d'}};
        Solution sol = new Solution();
        List<String> res = sol.findWords(board,words);
        for(int i =0;i <res.size();i++){
            System.out.println(res.get(i));
        }
    }

}