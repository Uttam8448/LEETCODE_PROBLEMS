/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* lptr=list1;
        ListNode* rptr=list2;
        ListNode* mptr=new ListNode(-1);
        ListNode* mergeHead=mptr;
        while(lptr!=NULL && rptr!=NULL ){
            if(lptr->val<=rptr->val){
                mptr->next=lptr;
                mptr=lptr;
                lptr=lptr->next;
            }
            else{
                mptr->next=rptr;
                mptr=rptr;
                rptr=rptr->next;
            }
        }
        while(lptr!=NULL){
            mptr->next=lptr;
            mptr=lptr;
            lptr=lptr->next;
        }
        while(rptr!=NULL){
            mptr->next=rptr;
            mptr=rptr;
            rptr=rptr->next;
        }
        mergeHead=mergeHead->next;
        return mergeHead;
    }
};