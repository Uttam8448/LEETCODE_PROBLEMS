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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* ansHead=new ListNode(1);
        ListNode* ansTail=ansHead;
        int sum=0;
        while(temp){
            if(temp->val==0 && sum>0){
                ListNode* help=new ListNode(sum);
                ansTail->next=help;
                ansTail=help;
                sum=0;
            }
            else{
                sum=sum+temp->val;
            }
            temp=temp->next;
        }
        ansHead=ansHead->next;
        return ansHead;
    }
};