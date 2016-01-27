/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        int total = 0;
        ListNode cur = head;
        while(cur!=null){
        	cur = cur.next;
        	total ++;
        }
        int count = 0;
        int times = total/k;
        int time = 0;
        cur = head;
        ListNode pre = null; 
        while(time++ < times){
        	count = 0;
        	ListNode st = cur;
        	while()
        	while(count++ < k){
        		ListNode tmp = cur.next;
        		swap(cur,cur.next,pre);
        		pre = tmp;
        	}
        }
    }
    private void swap(ListNode cur,ListNode next, ListNode pre){
    	ListNode tmp = next.next;
    	next.next = cur;
    	cur.next = tmp;
    	if(pre != null){
    		pre.next = next;
    	}

    }
}