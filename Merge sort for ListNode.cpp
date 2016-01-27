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
        int length = findLength(head);   //求出list的长度

        int width = 1;
        ListNode headFirst ;    //这个新的头指针，因为原来的head指针会变
        headFirst.next = head;
        for(; width <= length; width =width*2){
            ListNode *first = &headFirst;     //first 表示left之前的一个指针
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
                for(int j = 0; j < width-1; j++){  //找出middle指针
                    if(middle->next == NULL)
                        break;
                    middle = middle->next;
                }
                for(int j = 0; j < 2*width-1;j++){   //找出end指针
                    if(right->next == NULL)
                        break;
                    right = right->next;

                }
				for(int j = 0; j < 2*width; j++){    //这边的 i 是下一轮merge 的起始位置
                        if(i == NULL)
                            break;
                        i = i->next;

                }
                MergeSort(first,left,middle,right);
                for(int j = 0; j < 2*width; j++){  //这边找出下一轮 left指针的前一个指针
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
			if(left == last && rightBegin == lastRig)  //最为重要！！！！

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
