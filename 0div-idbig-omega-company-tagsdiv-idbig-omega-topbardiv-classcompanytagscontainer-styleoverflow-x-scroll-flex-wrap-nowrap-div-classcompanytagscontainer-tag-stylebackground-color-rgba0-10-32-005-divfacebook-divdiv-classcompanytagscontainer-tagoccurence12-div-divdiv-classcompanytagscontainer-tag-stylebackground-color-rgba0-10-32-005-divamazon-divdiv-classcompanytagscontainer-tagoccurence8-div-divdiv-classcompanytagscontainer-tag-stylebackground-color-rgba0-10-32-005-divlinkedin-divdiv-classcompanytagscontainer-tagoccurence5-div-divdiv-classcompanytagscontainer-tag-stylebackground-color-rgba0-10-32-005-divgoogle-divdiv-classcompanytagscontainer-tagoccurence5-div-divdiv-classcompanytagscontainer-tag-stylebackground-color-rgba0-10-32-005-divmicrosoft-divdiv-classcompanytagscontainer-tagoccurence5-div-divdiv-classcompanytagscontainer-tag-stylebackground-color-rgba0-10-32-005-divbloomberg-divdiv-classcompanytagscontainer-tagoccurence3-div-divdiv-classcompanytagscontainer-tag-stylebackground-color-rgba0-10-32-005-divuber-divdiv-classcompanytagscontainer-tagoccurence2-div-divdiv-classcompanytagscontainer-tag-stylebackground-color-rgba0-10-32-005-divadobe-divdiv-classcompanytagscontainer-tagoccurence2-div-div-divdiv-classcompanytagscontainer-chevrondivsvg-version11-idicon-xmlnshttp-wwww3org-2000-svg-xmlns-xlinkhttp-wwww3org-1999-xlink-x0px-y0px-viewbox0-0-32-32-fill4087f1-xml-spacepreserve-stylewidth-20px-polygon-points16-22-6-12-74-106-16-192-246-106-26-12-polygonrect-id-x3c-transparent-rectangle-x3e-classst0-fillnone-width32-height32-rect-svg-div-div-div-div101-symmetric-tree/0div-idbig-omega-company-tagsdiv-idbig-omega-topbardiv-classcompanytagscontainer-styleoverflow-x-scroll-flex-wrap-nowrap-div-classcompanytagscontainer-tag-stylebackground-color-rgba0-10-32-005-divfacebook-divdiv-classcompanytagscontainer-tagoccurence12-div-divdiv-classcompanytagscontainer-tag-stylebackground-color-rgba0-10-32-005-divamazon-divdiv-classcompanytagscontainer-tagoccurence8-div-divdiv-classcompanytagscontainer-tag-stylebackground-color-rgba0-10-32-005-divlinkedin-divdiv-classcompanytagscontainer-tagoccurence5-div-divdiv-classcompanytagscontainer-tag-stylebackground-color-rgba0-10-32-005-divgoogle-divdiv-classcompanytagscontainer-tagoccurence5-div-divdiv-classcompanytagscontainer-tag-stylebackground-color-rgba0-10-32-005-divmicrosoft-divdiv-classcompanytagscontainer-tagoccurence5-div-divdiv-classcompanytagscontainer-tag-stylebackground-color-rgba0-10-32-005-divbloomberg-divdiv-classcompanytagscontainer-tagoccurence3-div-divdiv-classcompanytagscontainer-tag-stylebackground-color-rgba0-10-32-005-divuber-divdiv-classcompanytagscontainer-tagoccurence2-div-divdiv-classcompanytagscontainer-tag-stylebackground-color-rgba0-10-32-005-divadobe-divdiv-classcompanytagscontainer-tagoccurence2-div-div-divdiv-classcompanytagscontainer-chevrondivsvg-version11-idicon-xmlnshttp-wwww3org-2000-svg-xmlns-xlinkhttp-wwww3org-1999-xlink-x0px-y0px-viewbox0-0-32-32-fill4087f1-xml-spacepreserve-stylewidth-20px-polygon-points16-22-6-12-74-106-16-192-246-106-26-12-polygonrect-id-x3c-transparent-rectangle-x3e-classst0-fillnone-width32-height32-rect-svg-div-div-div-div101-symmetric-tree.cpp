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
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if(p && q){
            if(p->val==q->val){
            bool b=1;
            bool bl=isSameTree(p->left, q->right);
            bool br=isSameTree(p->right, q->left);
            return (b && bl && br);
            }
        }
        return 0;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 0;
        return isSameTree(root->left,root->right);
    }
};