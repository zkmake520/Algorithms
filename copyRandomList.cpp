#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *cur = head;
        if(head == NULL)    return NULL;
        while(cur != NULL){
            RandomListNode *tmp = cur->next;
            RandomListNode *newNode = new RandomListNode(cur->label);
            cur->next = newNode;
            newNode->next = tmp;
            cur = tmp;
        }
        cur = head;
        //count for the random
        while(cur != NULL){
            if(cur->random !=NULL)
                cur->next->random = cur->random->next;
            else    cur->next->random = NULL;
            cur = cur->next->next;
        }
        RandomListNode * cur1=head;
        RandomListNode * cur2=head->next;
        RandomListNode * nhead = cur2;
        while(cur2->next!=NULL){
            cur1->next = cur2->next;
            cur2->next = cur2->next->next;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        cur1->next =NULL;
        cur2 = nhead;
        while(cur2!=NULL)
        {
            cout<<cur2->label<<cur2->random->label<<endl;
            cur2=cur2->next;
        }
        return nhead;
    }
};
int main(){
    Solution sol;
    RandomListNode *head = new RandomListNode(-1);
    head->random = head;
    RandomListNode *head1 = new RandomListNode(2);
    head1->random = head;
	 RandomListNode *head2 = new RandomListNode(3);
    head2->random = head1;
    head->next = head1,head1->next = head2;head2->next=NULL;
    RandomListNode * heaad2=sol.copyRandomList(head);
}
