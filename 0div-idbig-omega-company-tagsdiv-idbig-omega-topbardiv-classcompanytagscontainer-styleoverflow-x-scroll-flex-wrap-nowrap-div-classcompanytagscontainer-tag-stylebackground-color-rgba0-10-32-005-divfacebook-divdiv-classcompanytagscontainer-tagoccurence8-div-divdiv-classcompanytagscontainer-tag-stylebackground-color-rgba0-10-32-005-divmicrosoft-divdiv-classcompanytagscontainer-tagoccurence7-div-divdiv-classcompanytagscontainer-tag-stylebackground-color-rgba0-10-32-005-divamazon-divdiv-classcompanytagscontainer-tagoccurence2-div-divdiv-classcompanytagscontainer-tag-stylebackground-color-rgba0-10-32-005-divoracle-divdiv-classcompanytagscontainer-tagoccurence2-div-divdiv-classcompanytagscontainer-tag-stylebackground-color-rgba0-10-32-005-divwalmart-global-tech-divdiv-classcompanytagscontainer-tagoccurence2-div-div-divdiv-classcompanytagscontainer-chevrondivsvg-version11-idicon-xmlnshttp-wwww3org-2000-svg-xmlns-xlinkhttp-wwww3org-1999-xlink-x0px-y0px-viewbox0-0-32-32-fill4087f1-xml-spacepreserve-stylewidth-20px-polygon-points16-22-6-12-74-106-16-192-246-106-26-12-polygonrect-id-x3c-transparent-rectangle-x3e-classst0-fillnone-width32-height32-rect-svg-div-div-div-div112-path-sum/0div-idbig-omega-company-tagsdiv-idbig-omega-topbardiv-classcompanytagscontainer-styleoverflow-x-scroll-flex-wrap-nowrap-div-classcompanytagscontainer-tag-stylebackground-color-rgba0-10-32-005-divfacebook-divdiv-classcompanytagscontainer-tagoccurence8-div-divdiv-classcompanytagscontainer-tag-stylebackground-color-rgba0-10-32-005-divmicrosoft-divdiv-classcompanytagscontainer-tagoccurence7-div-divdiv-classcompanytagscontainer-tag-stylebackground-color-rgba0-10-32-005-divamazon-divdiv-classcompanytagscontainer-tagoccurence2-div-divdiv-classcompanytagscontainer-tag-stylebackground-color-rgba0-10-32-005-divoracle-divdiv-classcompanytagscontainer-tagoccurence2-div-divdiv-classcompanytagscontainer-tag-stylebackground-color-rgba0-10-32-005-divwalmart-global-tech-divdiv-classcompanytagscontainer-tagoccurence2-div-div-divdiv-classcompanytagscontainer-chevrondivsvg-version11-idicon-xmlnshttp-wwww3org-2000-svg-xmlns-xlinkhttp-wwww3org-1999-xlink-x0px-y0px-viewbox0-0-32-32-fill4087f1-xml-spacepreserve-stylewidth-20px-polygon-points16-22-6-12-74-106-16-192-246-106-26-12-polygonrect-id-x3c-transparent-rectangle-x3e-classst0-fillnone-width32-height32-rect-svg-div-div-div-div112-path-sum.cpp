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
    bool solve(TreeNode* root,int targetSum,int sum){
        if(root==NULL)
            return false;
        if(!root->left && !root->right){
            sum+=root->val;
            if(sum == targetSum)
                return true;
        }
        bool leftval=solve(root->left,targetSum,sum+root->val);
        bool rightval=solve(root->right,targetSum,sum+root->val);
        if(leftval || rightval)
            return true;
        return false;
            
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        int sum=0;
        bool ans=solve(root,targetSum,sum);
        return ans;
    }
};