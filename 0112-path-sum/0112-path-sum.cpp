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
    bool Solve(TreeNode* root,int sum,int targetSum){
        if(!root)   return false;
        if(!root->left && !root->right){
            if(targetSum==sum+root->val){
                return true;
            }
            return false;
        }
        bool leftAns=Solve(root->left,sum+root->val,targetSum);
        bool rightAns=Solve(root->right,sum+root->val,targetSum);
        return (leftAns || rightAns);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return Solve(root,0,targetSum);
    }
};