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
    int n;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){
        if(inStart>inEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[postEnd]);

        int i= inStart;
        for(; i<=inEnd; i++){
            if(root->val==inorder[i])
                break;
        }
        
        int leftsize= i- inStart;
        int rightsize= inEnd-i;

        root->left= solve(inorder, postorder,inStart, i-1, postStart, postStart+leftsize-1);
        root->right= solve(inorder, postorder,i+1, inEnd, postEnd-rightsize, postEnd-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n= inorder.size();
        
        return solve(inorder, postorder, 0, n-1, 0, n-1);
                    //(inorder, postorder, inStart, inEnd, postStart, postEnd);
    }
};