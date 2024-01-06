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
    bool b=1;
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lheight=height(root->left);
        int rheight=height(root->right);
        bool currans=(abs(lheight-rheight)<=1)?1:0;
        if(b && !currans)
            b=0;
        int ans=max(lheight,rheight);
        return ans+1;
    }
    bool isBalanced(TreeNode* root) {
        //base case
        if(root==NULL)
            return 1;
        height(root);
        return b;
    }
    
};