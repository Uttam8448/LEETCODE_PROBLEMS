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
 ListNode* FindMid(ListNode* &head){
	if(head == NULL){
		cout<<"LL is empty!!\n";
		return head;	
	}
	if(head->next==NULL){
		//Only 1 node
		return head;
	}
	//more than 1 node
	ListNode* slow = head;
	ListNode* fast = head;			//if even ans is n/2
	//for even ans n/2+1 use fast= head
	while(slow!= NULL && fast != NULL) {
		fast = fast->next;
		if(fast!=NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow;
}
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        return FindMid(head);
    }
};