#include<iostream>
#include<string>
#include<cstdlib>
#include <vector>
#include<time.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
  //  ListNode(int x) : val(x), next(NULL) {}
}List[10];

class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next ==NULL) return;  //从一半开始，将后面的list reverse 即可
        ListNode *nhead = head;
        int size = 0;
        while(nhead != NULL){
            size++;
            nhead = nhead->next;
        }
        nhead = head;
        int count = 1;
        int middle = size %2 == 0 ? size/2: size/2+1;
        while(count < middle)
            count++, nhead=nhead->next;
        ListNode *reverseHead = reverseList(nhead->next);
        ListNode *head2 = head;
        while(head2 != nhead){
            ListNode * tmp = head2->next;
            head2->next = reverseHead;
            ListNode *tmp2 = reverseHead->next;
            reverseHead->next = tmp;
            head2 = tmp;
            reverseHead = tmp2;
        }
        if(size%2 == 0)
            head2->next = reverseHead;
        else
            head2->next = NULL;
      /*  while(head !=NULL){
            cout<<head->val<<endl;
            head = head->next;
        }
*/
        return;

    }
    ListNode *reverseList(ListNode * head){
        ListNode *cur = head->next;
        ListNode *pre = head;
        while(cur != NULL){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur =tmp;
        }
        head->next = NULL;
        return pre;
    }
};
int main(){
    Solution sol;
     srand( (unsigned)time( NULL ) );
    for(int i =0; i< 10;i++){

        List[i].next = &List[i+1];
    }

    List[0].val = 0;
     List[1].val = 1;
      List[2].val = 2;
       List[3].val = 3;
        List[4].val = 4;
         List[5].val = 5; List[6].val = 6;
          List[7].val = 7;
           List[8].val = 8;
            List[9].val = 9;
    List[8].next = NULL;
    sol.reorderList(&List[0]);

}

