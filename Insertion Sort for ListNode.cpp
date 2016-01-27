#include<cstdlib>
#include<string>
#include<time.h>
#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode  *start =new ListNode();
        start->next = head;
        head = head->next;
        ListNode *head2;
        int count = 1;
        for(; head != NULL ; head = head->next ){
            ListNode *ff = start;
            for(int i =0;i < 10; i++){
                 start= start->next;
                cout<<head->val<<endl;
            }
            head2 = start->next;
            ListNode *head2Front = start;
			ListNode *end = NULL;
			int changed = 0;
			int i = 0;
            for( i = 0; i< count; i++){
                if(head->val <= head2->val){
                    head2Front ->next = head;
					 end = head->next;
					 changed = 1;
                    head->next = head2;
                }
				if(changed == 1){
                    while(i != count-1){
                        i++;
                        head2 = head2->next;
                    }
                    head2->next = end;
					break;
				}
                head2Front = head2Front->next;
                head2 = head2->next;

			}
            count++;
        }
        return start->next;
    }
};
int main(){

    Solution sol;
    srand( (unsigned)time( NULL ) );
    ListNode List[10];
    for(int i =0;i < 10;i++){
        List[i].val =rand()%12;
        List[i].next = &List[i+1];
    }
    List[9].next = NULL;
    ListNode *head = sol.insertionSortList(&List[0]);
    for(int i =0;i < 10; i++){
            head = head->next;
        cout<<head->val<<endl;

    }
}
