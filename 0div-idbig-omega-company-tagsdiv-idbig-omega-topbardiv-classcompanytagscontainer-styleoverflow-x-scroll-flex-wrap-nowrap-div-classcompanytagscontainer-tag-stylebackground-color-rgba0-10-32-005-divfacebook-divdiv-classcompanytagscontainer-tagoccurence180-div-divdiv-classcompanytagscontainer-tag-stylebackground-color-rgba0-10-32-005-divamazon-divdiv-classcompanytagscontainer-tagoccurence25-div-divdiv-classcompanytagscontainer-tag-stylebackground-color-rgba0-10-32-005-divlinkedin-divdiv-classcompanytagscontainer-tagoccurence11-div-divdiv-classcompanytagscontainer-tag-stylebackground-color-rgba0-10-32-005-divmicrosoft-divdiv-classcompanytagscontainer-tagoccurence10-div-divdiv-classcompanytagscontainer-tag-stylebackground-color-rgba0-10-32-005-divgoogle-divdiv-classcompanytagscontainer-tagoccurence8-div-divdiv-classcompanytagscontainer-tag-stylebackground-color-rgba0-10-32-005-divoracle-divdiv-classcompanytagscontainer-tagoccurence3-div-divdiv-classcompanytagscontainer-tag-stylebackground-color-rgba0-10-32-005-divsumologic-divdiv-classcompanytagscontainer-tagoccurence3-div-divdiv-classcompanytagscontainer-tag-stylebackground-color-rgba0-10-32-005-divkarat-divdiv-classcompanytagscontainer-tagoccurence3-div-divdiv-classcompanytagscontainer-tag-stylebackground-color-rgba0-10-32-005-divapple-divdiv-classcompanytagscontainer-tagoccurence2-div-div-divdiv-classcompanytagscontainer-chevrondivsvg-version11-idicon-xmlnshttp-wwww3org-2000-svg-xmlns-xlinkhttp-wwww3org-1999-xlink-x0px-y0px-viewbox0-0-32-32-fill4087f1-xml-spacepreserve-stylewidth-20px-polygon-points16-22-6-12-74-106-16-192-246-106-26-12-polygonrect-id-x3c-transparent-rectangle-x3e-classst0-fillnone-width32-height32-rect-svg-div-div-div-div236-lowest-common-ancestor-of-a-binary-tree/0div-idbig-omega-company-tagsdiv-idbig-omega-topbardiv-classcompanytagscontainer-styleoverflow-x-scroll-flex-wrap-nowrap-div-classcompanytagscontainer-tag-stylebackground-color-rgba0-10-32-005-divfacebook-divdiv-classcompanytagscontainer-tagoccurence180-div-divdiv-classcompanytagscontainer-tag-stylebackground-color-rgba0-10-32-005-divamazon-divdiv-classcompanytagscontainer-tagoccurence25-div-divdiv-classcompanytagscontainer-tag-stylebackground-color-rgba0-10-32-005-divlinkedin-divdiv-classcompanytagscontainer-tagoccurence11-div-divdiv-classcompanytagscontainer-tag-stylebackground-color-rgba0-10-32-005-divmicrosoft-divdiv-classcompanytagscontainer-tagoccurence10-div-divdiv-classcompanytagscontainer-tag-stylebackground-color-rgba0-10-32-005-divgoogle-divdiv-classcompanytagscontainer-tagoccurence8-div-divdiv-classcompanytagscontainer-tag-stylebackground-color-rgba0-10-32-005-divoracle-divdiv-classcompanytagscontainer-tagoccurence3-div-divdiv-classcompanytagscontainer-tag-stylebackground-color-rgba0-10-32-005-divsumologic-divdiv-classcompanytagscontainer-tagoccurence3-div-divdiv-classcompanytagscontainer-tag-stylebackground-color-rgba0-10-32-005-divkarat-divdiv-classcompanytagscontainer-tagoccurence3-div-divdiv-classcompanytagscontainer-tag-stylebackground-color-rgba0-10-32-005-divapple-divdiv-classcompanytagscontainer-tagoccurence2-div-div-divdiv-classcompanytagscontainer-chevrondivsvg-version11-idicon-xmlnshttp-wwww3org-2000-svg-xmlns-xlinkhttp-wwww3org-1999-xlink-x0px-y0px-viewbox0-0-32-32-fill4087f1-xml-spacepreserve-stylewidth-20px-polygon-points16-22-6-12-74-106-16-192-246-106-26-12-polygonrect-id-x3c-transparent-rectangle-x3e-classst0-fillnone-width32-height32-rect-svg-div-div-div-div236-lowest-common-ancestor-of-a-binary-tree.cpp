/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root->val==p->val)
            return p;
        if(root->val==q->val)
            return q;
        TreeNode* leftval=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightval=lowestCommonAncestor(root->right,p,q);
        if(leftval==NULL && rightval==NULL)
            return NULL;
        else if(leftval!=NULL && rightval==NULL)
            return leftval;
        else if(leftval==NULL && rightval!=NULL)
            return rightval;
        return root;
    }
}; 