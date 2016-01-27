import java.util.*;

/**
 * Created by zkwangchao on 15/8/26.
 */

public class Solution {
    public String shortestPalindrome(String s) {
        String t = s;
        StringBuilder sb = new StringBuilder();
        sb.append('$');
        for(int i = 0 ;i < s.length();i++){
            sb.append('#');
            sb.append(s.charAt(i));

        }
        sb.append('#');
        s = sb.toString();
        int mx = 0;
        int center = 0;
        int [] p = new int[s.length()+1];
        p[0] = 0;
        for(int i = 1; i < s.length(); i++){
            int mirror = 2*center-i;
            p[i] = mx>i?Math.min(p[mirror],mx-i):0;
            while(i+p[i]+1 < s.length() && i-p[i]-1 >=0 && s.charAt(i+p[i]+1) == s.charAt(i-p[i]-1)){
                p[i]++;
            }
            if(i+p[i] > mx){
                mx = i+p[i];
                center = i;
            }
        }
        int pos = 0;
        for (int i = s.length()-1; i>=1;i--){
            if(i-p[i] == 1){
                pos = p[i];
                break;
            }
        }
        String ss = t.substring(pos);
        String tt= new StringBuilder(ss).reverse().toString();
        return tt +t;

    }
    public  static void main(String[] args) {
        Solution sol = new Solution();
        System.out.print((sol.shortestPalindrome("abbacd")));
    }

}
