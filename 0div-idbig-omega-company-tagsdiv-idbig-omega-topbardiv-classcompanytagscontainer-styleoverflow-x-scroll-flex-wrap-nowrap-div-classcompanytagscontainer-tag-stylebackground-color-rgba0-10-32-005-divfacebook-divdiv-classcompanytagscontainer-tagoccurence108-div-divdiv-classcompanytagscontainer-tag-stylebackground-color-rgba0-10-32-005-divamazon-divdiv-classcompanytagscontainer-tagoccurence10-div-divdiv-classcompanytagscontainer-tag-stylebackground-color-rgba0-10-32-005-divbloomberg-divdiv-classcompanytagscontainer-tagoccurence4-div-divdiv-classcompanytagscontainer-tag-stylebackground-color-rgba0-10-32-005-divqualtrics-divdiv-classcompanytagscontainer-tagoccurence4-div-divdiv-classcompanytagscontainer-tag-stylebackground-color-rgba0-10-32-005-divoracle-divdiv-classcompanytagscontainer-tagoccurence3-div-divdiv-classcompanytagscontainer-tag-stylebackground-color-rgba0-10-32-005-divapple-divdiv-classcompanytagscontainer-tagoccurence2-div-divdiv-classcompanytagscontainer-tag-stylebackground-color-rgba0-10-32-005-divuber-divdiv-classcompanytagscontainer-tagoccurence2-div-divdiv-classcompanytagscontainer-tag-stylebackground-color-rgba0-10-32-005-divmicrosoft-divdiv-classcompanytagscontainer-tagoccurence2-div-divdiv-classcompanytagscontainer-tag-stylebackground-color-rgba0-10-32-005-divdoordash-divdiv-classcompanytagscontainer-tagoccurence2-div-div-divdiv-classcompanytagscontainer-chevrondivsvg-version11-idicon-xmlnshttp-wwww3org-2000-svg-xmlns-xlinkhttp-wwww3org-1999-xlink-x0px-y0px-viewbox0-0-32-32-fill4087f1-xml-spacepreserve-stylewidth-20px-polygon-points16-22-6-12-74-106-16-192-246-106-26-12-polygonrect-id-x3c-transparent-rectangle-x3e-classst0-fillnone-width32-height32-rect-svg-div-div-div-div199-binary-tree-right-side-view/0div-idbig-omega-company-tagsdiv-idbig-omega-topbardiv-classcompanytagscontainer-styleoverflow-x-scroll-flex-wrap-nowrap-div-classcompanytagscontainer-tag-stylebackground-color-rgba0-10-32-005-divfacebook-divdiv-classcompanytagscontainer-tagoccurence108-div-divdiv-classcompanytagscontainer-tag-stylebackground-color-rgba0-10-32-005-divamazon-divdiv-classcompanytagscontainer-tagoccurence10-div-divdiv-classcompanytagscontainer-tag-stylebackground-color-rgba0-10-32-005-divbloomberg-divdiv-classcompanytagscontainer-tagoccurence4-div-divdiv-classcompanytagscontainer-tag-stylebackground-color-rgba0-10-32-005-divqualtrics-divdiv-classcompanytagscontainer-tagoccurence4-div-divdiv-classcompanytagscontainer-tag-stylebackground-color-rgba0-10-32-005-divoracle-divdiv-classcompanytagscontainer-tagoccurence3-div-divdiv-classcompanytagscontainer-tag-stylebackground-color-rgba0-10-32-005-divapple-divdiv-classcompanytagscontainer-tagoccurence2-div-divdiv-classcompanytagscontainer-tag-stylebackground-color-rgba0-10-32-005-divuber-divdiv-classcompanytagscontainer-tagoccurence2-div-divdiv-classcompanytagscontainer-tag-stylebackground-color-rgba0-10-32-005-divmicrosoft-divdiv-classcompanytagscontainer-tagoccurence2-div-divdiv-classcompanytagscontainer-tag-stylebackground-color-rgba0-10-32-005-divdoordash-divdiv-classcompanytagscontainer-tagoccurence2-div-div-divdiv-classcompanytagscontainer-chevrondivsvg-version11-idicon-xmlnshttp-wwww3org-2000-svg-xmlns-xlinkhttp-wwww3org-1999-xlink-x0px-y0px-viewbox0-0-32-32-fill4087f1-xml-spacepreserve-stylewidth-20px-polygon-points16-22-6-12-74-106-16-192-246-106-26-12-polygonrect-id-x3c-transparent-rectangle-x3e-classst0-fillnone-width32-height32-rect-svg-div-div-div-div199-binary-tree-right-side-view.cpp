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
        void Solve(TreeNode* root,int level,vector<int>& rightview){
    if(root==NULL)
        return;
    if(level==(rightview.size())){
        rightview.push_back(root->val);
        
    }
    Solve(root->right,level+1,rightview);
    Solve(root->left,level+1,rightview);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightview;
        Solve(root,0,rightview);
        return rightview;
    }
};