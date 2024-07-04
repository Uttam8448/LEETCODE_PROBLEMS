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
bool flag=false;
void fun(ListNode* &head,int& k,int size){

}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int ans=-1;
        int size=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            size++;
        }
        if(size==n) {
            head=head->next;
            return head;
        }
        int it=size-n;
        temp=head;
        while(it!=1){
            temp=temp->next;
            it--;
        }
        ListNode* temp2=temp->next->next;
        temp->next=temp2;
        return head;

    }
};