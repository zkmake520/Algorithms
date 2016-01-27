class TrieNode {
    // Initialize your data structure here.
    boolean isLeaf;
    HashMap<char, TrieNode> subNodes = new HashMap<char,TrieNode>();
    public TrieNode(){

    }
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        HashMap<char TrieNode> subNodes = root.subNodes;
        for(int i =0;i < word.length; i++){
            char c = word[i];
            TrieNdoe t;
            if(subNodes.containsKey(c)){
                t = subNodes.get(c);
            } else{
                t = new TrieNode();
                subNodes.put(c,t);
            }
            subNodes = t.subNodes;
            if(i == word.length - 1){
               t.isLeaf = true;
            }
        } 
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        TrieNode t= searchNode(word);
        return t!=null && t.isLeaf;
    }
    private TrieNode searchNode(string word){
         HashMap<char ,TrieNode> subNodes = root.subNodes;
         TrieNode t= root;
         for(int i = 0; i <word.length; i++){
            if(subNodes.containsKey(word[i])){
                t = subNodes.get(word[i]);
                subNodes = t.subNodes; 
            }
            else{
                return null;
            }
         }
         return t;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
       return searchNode(prefix) != null; 
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");