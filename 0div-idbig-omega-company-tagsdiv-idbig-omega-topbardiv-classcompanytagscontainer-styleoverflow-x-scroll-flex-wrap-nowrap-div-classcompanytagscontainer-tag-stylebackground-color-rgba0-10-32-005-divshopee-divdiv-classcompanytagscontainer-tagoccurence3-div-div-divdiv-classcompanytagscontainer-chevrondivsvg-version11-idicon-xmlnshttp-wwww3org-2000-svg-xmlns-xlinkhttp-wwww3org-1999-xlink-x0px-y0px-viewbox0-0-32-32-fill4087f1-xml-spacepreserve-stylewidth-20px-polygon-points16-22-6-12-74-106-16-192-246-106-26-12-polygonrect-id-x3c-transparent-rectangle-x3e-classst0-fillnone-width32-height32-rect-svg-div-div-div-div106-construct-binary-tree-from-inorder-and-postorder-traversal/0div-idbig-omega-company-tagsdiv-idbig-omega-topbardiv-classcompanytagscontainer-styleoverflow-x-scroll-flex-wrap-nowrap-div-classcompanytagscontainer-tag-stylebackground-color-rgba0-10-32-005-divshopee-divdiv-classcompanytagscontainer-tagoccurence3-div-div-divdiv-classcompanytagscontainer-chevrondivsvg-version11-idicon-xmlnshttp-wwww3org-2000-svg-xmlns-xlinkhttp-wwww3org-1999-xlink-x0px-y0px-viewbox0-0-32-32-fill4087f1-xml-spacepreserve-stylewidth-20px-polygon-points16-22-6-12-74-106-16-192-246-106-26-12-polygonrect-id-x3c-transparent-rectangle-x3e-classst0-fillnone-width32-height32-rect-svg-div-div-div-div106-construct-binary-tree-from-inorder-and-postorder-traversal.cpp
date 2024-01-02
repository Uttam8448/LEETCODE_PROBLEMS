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
    void createMapping(map<int,int>& valueToIndexMap,vector<int>& inorder,int size){
        for(int i=0;i<size;i++){
            int element=inorder[i];
            int index=i;
            valueToIndexMap[element]=index;
        }
    }
    TreeNode* Solve( map<int,int>& valueToIndexMap,vector<int>& inOrder, vector<int>& postOrder,int& postIndex,int inIndexStart,int inIndexEnd,int size){
        if(postIndex<0 || inIndexStart > inIndexEnd)
            return NULL;
        int element = postOrder[postIndex];
        postIndex--;
        TreeNode* root = new TreeNode(element);
        int position = valueToIndexMap[element];
        root->right = Solve(valueToIndexMap,inOrder,postOrder,postIndex,position+1,inIndexEnd,size);
        root->left = Solve(valueToIndexMap,inOrder,postOrder,postIndex,inIndexStart,position-1,size);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=postorder.size();
        int postIndex=size-1;
        int inIndexStart=0;
        int inIndexEnd=size-1;
        map<int,int> valueToIndexMap;
        createMapping(valueToIndexMap,inorder,size);
        TreeNode* root=Solve(valueToIndexMap,inorder,postorder,postIndex,inIndexStart,inIndexEnd,size);
        return root;
        
    }
};