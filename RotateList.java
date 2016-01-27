/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
    	int i = 0;
    	int count = 1;
    	if(head == null){
    		return head;
    	}
    	ListNode begin = head;
    	ListNode tail = null;
       	while(head->next != null){
       		head= head->next;
       		count++;
       	}
       	tail = head;
       	head = begin;
       	for(int i = 0; i < count-k-1; i++){
       		head = head->next;
       	}
       	tail->next = begin;
       	begin = head->next;
       	head->next = null;
       	return  begin;

    }
}