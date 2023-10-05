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
    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;
        ListNode* tail=head;
        if( k==0 || head==NULL){
            return head;
        }
        int length=getLength(head);
        int actualRotateK = k % length;
        if(!actualRotateK) return head;
        int newLastNodePos = length - actualRotateK - 1;
        ListNode*newhead = nullptr;
        ListNode* newLastNode = head;
        for(int i=0;i<newLastNodePos;i++){
            newLastNode=newLastNode->next;
        }
        ListNode*newHead = newLastNode->next;
        newLastNode->next=0;
        ListNode*it = newHead;
        while(it->next){
            it=it->next;
        }
        it->next=head;
        return newHead;
    }
};