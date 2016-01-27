#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;


}List[30];
class  Solution{
public:
     ListNode *sortList(ListNode *head){
        int length = findLength(head);   //���list�ĳ���

        int width = 1;
        ListNode headFirst ;    //����µ�ͷָ�룬��Ϊԭ����headָ����
        headFirst.next = head;
        for(; width <= length; width =width*2){
            ListNode *first = &headFirst;     //first ��ʾleft֮ǰ��һ��ָ��
			ListNode *ff = &headFirst;
			for(int i =0;i < 8; i++){
				ff = ff->next;
				 cout<<ff->val<<endl;


			 }
			cout<<"\n"<<endl;
            for(ListNode *i = headFirst.next; i != NULL;){
                ListNode *left =i;
                ListNode *middle,*right;
                middle = right = left;
                for(int j = 0; j < width-1; j++){  //�ҳ�middleָ��
                    if(middle->next == NULL)
                        break;
                    middle = middle->next;
                }
                for(int j = 0; j < 2*width-1;j++){   //�ҳ�endָ��
                    if(right->next == NULL)
                        break;
                    right = right->next;

                }
				for(int j = 0; j < 2*width; j++){    //��ߵ� i ����һ��merge ����ʼλ��
                        if(i == NULL)
                            break;
                        i = i->next;

                }
                MergeSort(first,left,middle,right);
                for(int j = 0; j < 2*width; j++){  //����ҳ���һ�� leftָ���ǰһ��ָ��
                        if(first == NULL)
                            break;
                        first = first->next;

                }
            }

        }
        return headFirst.next;
    }
    void MergeSort(ListNode *first, ListNode *left, ListNode *middle, ListNode *right){
        ListNode *rightBegin = middle->next;
        ListNode *beg = left;
        if(left == middle){
            if(left->val <= right->val)
                return;
            else{
                left->next = right->next;
                right->next = left;
                first->next = right;
                return;
            }
        }
        ListNode *last = rightBegin;
		ListNode *lastRig = right->next;
        while(left != last || rightBegin != lastRig){
            if(left == last){
                first->next = rightBegin;
                rightBegin = rightBegin->next;
            }
            else if(rightBegin == lastRig){
                first->next = left;
                left = left->next;
            }
            else if(left != last && rightBegin!=lastRig && left->val < rightBegin->val){
                first->next = left;
                left = left->next;
            }
            else if(left != last && rightBegin!=lastRig && left->val >= rightBegin->val){
                first->next = rightBegin;
                rightBegin = rightBegin->next;
            }

            first = first->next;
			if(left == last && rightBegin == lastRig)  //��Ϊ��Ҫ��������

				first->next = lastRig;
        }
    }
    int  findLength(ListNode *head){
        ListNode *node = head;
        int count = 0;
        while(node != NULL){

            count++;
            node = node->next;
        }

        return count;
    }
};
int main()
{
    Solution sol;

     srand( (unsigned)time( NULL ) );
    for(int i =0;i < 9;i++){
		List[i].val = rand()%12;
        List[i].next = &List[i+1];
    }


    List[8].next = NULL;
    ListNode *head = sol.sortList(&List[0]);
    for(int i =0;i < 9; i++){

        cout<<head->val<<endl;
		   head = head->next;

    }
}
