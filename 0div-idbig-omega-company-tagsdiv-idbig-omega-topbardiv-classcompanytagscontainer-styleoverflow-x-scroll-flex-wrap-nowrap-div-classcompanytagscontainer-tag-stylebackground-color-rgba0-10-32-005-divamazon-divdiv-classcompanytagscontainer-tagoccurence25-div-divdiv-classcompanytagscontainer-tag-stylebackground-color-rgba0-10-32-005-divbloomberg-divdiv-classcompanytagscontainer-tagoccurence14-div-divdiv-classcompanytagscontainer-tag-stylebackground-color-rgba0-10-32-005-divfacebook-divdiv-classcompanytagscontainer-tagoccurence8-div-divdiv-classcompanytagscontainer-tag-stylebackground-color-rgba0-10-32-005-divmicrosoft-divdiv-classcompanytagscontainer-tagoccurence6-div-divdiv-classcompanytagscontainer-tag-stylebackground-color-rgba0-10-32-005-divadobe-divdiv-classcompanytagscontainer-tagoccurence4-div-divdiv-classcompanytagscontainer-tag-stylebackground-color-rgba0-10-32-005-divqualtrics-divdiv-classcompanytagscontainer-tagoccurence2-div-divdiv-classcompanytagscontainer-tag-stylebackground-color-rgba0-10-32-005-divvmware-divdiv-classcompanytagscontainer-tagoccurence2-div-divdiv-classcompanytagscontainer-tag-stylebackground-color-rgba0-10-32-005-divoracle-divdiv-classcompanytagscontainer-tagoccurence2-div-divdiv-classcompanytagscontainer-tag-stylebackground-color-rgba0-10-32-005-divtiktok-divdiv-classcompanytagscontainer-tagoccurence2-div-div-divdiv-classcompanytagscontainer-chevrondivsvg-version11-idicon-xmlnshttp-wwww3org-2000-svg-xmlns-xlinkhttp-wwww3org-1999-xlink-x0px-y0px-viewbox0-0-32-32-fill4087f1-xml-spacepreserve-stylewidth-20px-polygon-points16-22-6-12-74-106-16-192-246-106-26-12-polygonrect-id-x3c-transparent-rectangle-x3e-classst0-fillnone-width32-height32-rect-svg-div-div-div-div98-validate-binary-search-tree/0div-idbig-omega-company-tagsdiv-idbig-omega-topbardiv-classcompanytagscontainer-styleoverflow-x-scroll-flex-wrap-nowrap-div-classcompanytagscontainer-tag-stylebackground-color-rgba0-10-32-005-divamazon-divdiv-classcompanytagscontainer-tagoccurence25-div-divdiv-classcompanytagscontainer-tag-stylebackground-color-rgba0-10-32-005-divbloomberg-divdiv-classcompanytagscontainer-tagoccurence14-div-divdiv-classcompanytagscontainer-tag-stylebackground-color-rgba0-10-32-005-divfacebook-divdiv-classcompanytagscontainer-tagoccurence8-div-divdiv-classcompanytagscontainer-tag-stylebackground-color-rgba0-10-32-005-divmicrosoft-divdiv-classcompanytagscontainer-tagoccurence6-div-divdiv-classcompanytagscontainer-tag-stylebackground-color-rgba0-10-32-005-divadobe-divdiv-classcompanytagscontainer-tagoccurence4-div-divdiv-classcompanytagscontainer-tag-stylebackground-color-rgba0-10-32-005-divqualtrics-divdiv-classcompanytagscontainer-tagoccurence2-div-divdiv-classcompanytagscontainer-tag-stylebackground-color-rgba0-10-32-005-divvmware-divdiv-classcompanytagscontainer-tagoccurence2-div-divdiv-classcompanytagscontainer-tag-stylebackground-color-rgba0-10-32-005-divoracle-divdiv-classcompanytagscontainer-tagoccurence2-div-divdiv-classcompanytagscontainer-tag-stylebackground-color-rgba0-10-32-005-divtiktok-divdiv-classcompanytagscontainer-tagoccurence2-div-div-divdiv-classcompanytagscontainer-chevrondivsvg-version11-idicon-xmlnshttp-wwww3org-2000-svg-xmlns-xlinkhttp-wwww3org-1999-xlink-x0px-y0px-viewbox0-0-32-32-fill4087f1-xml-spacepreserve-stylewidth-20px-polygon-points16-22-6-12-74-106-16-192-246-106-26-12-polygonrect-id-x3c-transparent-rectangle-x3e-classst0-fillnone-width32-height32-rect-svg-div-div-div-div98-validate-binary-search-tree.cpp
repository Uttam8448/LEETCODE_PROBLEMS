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
    bool Solve(TreeNode* root,long long int l,long long int u){
        if(!root)   return true;
        if(root->val>l && root->val<u){
            bool leftans=Solve(root->left,l,root->val);
            bool rightans=Solve(root->right,root->val,u);
            return (leftans&&rightans);
        }
        else
            return false;     
    }
    bool isValidBST(TreeNode* root) {
        long long int LowerBound=-4294967296;
        long long int UpperBound=4294967296;
        return Solve(root,LowerBound,UpperBound);
    }
};