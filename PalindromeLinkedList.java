public class Solution {
    public boolean isPalindrome(ListNode head) {
    	if(head == null || head.next == null){
    		return true;
    	}
        ListNode t1 = head;
        int count = 0;
        while(head != null){
        	head = head.next;	
        	count++;
        }
        int sign = 1;
        int i = 0;
        if(count % 2 ==0){
        	sign =1;
        }
        else{
        	sign = -1;
        }
        int mid = count/2;
        ListNode tmp= null;
        ListNode pre = null;
        while(i < mid){
        	tmp = t1.next;
        	t1.next= pre;
    		pre =t1;
        	t1= tmp;
        	i++;
        }
        if(sign == -1){
        	t1= t1.next;
        }
        while(t1 != null){
        	if(t1.val != pre.val){
        		return false;
        	}
        	t1 = t1.next;
        	pre =pre.next;
        }
        return true;

    }
}