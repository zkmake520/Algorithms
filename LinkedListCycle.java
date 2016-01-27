public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null){
        	return false;
        }
        ListNode one = head.next;
        ListNode two = head.next.next;
        while(one != null && two != null){
        	if(one == two){
        		return true;
        	}
        	one = one.next;
        	if(two.next == null){
        		return false;
        	}
        	else{
        		two = two.next.next;
        	}
        }
        return false;
    }
}