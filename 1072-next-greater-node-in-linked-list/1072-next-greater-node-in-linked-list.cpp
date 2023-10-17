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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
        while(head!=NULL){
            ll.push_back(head->val);
            head=head->next;
        }
        vector<int> ans(ll.size(),0);
        stack<int> index;
        int i=0;
        for(i=0;i<ll.size();i++){
            while(!index.empty() && ll[i] > ll[index.top()]){
                int kids = index.top();
                index.pop();
                ans[kids] = ll[i];
            }
            index.push(i);
        }
        return ans;
    }
};