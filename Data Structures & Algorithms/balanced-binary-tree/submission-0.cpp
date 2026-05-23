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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;
        if(abs(height(root->left)-height(root->right))<2) return true;
        return false;
        
    }
    int height(TreeNode* root){
        if(!root) return false;
        return 1+max(height(root->left),height(root->right));
    }
};
