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
ListNode* merge(ListNode* list1, ListNode* list2){
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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL){
            return head;
        }

        //break LL into halves using mid nodes
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        //sort RE
        left = sortList(left);
        right = sortList(right);

        //merge both left ans right LLs
        ListNode* mergedLL =merge(left,right);
        return mergedLL;
    }
};