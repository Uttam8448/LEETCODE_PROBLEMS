/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a->next!=NULL && b->next!=NULL){
            if(a==b){
                return a;           //for same length of both linked list
            } 
            a=a->next;
            b=b->next;
        }
        int alen=0;
        int blen=0;
        while(a->next!=NULL){
            alen++;
            a=a->next;
        }
        while(b->next!=NULL){
            blen++;
            b=b->next;
        }
        while(alen!=0){
            alen--;
            headA=headA->next;
        }
        while(blen!=0){
            blen--;
            headB=headB->next;
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};