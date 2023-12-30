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
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        int lheight=height(root->left);
        int rheight=height(root->right);
        int ans=max(lheight,rheight);
        return ans+1;
    }
    bool isBalanced(TreeNode* root) {
        //base case
        if(root==NULL)
            return 1;
        bool currans=(abs(height(root->left)-height(root->right))<=1)?1:0;
        bool lbalanced=isBalanced(root->left);
        bool rbalanced=isBalanced(root->right);
        if(lbalanced && rbalanced && currans)
            return 1;
        else
            return 0;
    }
    
};