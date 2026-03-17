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
        if(root==NULL){
            return 0;
        }
        int left= height(root->left);
        int right= height(root->right);
        int ans= max(left, right) + 1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left_part= diameterOfBinaryTree(root->left);
        int right_part= diameterOfBinaryTree(root->right);
        int both= height(root->left)+ height(root->right);

        int ans= max(both, max(left_part, right_part));
        return ans;
    }
};