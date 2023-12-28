/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* temp;
        temp=root;
        if(root==NULL)
            return ans;
        stack<TreeNode*> s;
        while(1){
            if(temp!=NULL){
                ans.push_back(temp->val);
                s.push(temp);
                temp=temp->left;
            }
            else{
                if(s.empty()) 
                    break;
                temp=s.top();
                s.pop();
                temp=temp->right;
            }
        }
        return ans;
    }
};