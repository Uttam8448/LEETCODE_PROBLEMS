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
    void solve(TreeNode* root,int targetSum,int sum,vector<int> temp,vector<vector<int>>& ans){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            sum+=root->val;
            temp.push_back(root->val);
            if(sum==targetSum)
                ans.push_back(temp);
            else
                return;
        }
        temp.push_back(root->val);
        solve(root->left,targetSum,sum+root->val,temp,ans);
        solve(root->right,targetSum,sum+root->val,temp,ans);
    } 
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        int sum=0;
        vector<int> temp;
        solve(root,targetSum,sum,temp,ans);
        return ans;
    }
};