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
    int searchInorder(vector<int>& inOrder,int size, int target){
        for (int i=0;i<size;i++)
            if(inOrder[i] == target)
                return i;
        return -1;
    }
    TreeNode* Solve(vector<int>& inOrder,vector<int>& preOrder,int size,int& preIndex,int inOrderStart,int inOrderEnd){
	// base case
        if(preIndex >= size || inOrderStart > inOrderEnd ){
            return NULL;
        }

        int element = preOrder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(element);
        //element search krna padega inorder me
        int position = searchInorder(inOrder,size,element);
        root->left = Solve(inOrder,preOrder,size,preIndex,inOrderStart,position-1);
        root->right = Solve(inOrder,preOrder,size,preIndex,position+1,inOrderEnd);
        return root;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size=preorder.size();
	    int preIndex = 0;
	    int inOrderStart = 0;
	    int inOrderEnd = preorder.size()-1;
        TreeNode* root = Solve(inorder,preorder,size,preIndex,inOrderStart,inOrderEnd);
        return root;
    }
};