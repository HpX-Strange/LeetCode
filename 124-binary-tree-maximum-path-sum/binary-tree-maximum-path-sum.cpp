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
    int ans;

    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left= solve(root->left);
        int right= solve(root->right);

        int only_one_side= max(left,right)+root->val;
        int answer_is_below= left+right+root->val;
        int only_root= root->val;

        ans= max({ans, only_one_side, answer_is_below, only_root});
        return max(only_one_side, only_root);

    }

    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        solve(root);
        return ans;
    }
};