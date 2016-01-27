struct ListNode{
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre;
        ListNode *cur;
        pre = NULL;
        cur = head;
        while(cur != NULL){
        	if(cur->val == val){
        		if(cur == head){
        			head = head->next;
        
        		}
        		else{
        			pre->next = cur->next;
        		}
        	}else{
        		pre = cur;
        	}
        	cur = cur->next;
        }
        return head;
    }
};