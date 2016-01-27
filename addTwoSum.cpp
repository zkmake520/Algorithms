//
//  addTwoSum.cpp
//  
//
//  Created by zkwangchao on 14-4-8.
//
//

//
//  lengthOfLongestSubString.cpp
//
//
//  Created by zkwangchao on 14-4-8.
//
//

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {  //pay attention to that the number may be larger than int
public:             //and the beginning digit may be zero
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * head1 = l1;
        ListNode * head2 = l2;
        int64_t n1 = 0;
        int64_t n2 = 0;
        int count1 = 0;
        int f1 = 1;
        int f2 = 1;
        int count2 = 0;
        while(l1!=NULL){
            if(l1 ->val == 0 && f1 == 1)
                count1++;
            if(l1->val != 0)
                f1 = 0;
            n1 = n1*10+l1->val;
            l1 = l1->next;
            
        }
        while(l2!=NULL){
            if(l2 ->val == 0 && f2 == 1)
                count2++;
            if(l2->val != 0)
                f2 = 0;
            n2 = n2*10+l2->val;
            l2 = l2->next;
        }
        
        int64_t n1R = 0;
        int64_t n2R = 0;
        while(n1!=0){
            n1R = n1R*10+n1%10;
            n1 = n1/10;
        }
        while(count1){
            n1R =n1R*10;
            count1--;
        }
        while(n2!=0){
            n2R = n2R*10+n2%10;
            n2 = n2/10;
        }
        
        while(count2){
            n2R =n2R*10;
            count2--;
        }
        
        
        int64_t n = n1R+n2R;
        //  cout<<n<<endl;
        if(head1 == NULL)
            head1 = new ListNode(0);
        head2  = head1;
        while(n){
            head1->val = n%10;
            n = n/10;
            if(n == 0){ head1->next = NULL;  break;}
            if(head1->next)
                head1 = head1->next;
            else{
                head1->next = new ListNode(0);
                head1 = head1->next;
            }
        }
        return head2;
    }
};
int main(){
    
    Solution sol;
    ListNode *l1 = new ListNode(0);
    ListNode *l3 = new ListNode(8);
    ListNode *l5 = new ListNode(6);
    ListNode *l2 = new ListNode(4);
    ListNode *l4 = new ListNode(5);
    ListNode *l6 = new ListNode(6);
    
    l1->next = l3;
    l3->next = l5;
    l5->next = NULL;
    l2 ->next = l4;
    l4->next = l6;
    l6->next = NULL;
    
    
    ListNode *head2 = sol.addTwoNumbers(l1,l2);
    while(head2){
        cout<<head2->val;
        head2= head2->next;
    }
}
