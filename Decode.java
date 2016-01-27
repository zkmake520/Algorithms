import java.util.*;
public class Decode {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for(int i =0; i < strs.size(); i++){
            sb.append(strs.get(i).length()+"#");
            sb.append(strs.get(i));
        }
        return sb.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> rst = new ArrayList<String>();
        int i = 0;
        System.out.println(s);
        while(i<s.length()){
           
            int len = 0; 
            while(s.charAt(i) != '#'){
                len = len*10+s.charAt(i)-'0';
                i++;
            }
            int st = i+1;
            int e = len+i+1;
            System.out.println("len:"+len+" s:"+st+" e:"+e+" substring:"+s.substring(i+1,len+i+1));
            rst.add(s.substring(i+1,len+i+1));
            i = i+1+len;
        }
        return rst;
    }
    public static void main(String[] args){
        Decode decode = new Decode();
        List<String> strs = new ArrayList<>(Arrays.asList("63/Rc","h","BmI3FS~J9#vmk","7uBZ?7*/","24h+X","O "));
        List<String> rst = decode.decode(decode.encode(strs));
        for(String str: rst){
            System.out.println(str);
        }
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));