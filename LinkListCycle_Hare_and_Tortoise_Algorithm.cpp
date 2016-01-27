#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)  return head;
        ListNode *result = hareTortoiseAlgorithm(head);
        return result;
    }
    ListNode * hareTortoiseAlgorithm(ListNode *head){
        ListNode *oneStep = head->next;
        ListNode *twoStep = head->next->next;
        while(oneStep != twoStep){ //find the coincdence
            if(!oneStep || !twoStep)    return NULL;
            oneStep = oneStep->next;
            if(!(twoStep->next))   return NULL;
            twoStep = twoStep->next->next;
        } //相遇点设为m，开始到cycle start 为 x,then x+m % cycle length =0.此时two在m 再走x到了start处，head再走x也到start处，即相等
        oneStep = head;
        while(twoStep != oneStep){
            oneStep = oneStep->next;
            twoStep = twoStep->next;
        }
        return oneStep;

    }
};
