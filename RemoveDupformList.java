/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode begin = new ListNode(-1);
       	ListNode cur = head;
       	ListNode pre = begin;
       	if(head == null){
       	    return null;
       	}
       	while(cur.next != null){
       		if(cur.val == cur.next.val){
	       		while(cur.next != null && cur.val == cur.next.val){
       				cur = cur.next;
       			}
       			if(cur.next == null){
       				pre.next = null;
       				return begin.next;
       			}
       			cur =cur.next;
       		}
       		else{
       			pre.next = cur;
       			pre =cur;
       			cur = cur.next;
       		}
       	} 
       	pre.next = cur;
       	cur.next =null;
       	return begin.next;
    }
}