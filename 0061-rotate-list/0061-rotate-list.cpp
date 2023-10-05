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
    ListNode* helper(ListNode* head,ListNode* tail,ListNode* prev,int count){
            if(tail==NULL){ return 0;}
            helper(head,tail->next,tail,count);
            if(count!=0){
                tail->next=head;
                prev->next=NULL;
                head=tail;
                count--;
            }
            return head;
        
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int count=1;
        ListNode* tail=head;
        if( k==0 || head==NULL){
            return head;
        }
        while(tail->next!=NULL){
            count++;
            tail=tail->next;
        }
        int actualRotateK = k % count;
        int newLastNodePos = count - actualRotateK - 1;
        ListNode*newhead = nullptr;
        ListNode* newLastNode = head;
        for(int i=0;i<newLastNodePos;i++){
            newLastNode=newLastNode->next;
        }
        tail->next=head;
        head=newLastNode->next;
        newLastNode->next=NULL;
        return head;
    }
};