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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        int min = INT_MIN;
        int max = INT_MAX;
        return dfs(root, min, max);
        
    }
    bool dfs(TreeNode* root, int min, int max){
        if(root->val <= min || root->val >= max) return false;
        if(!root->right && !root->left) return true;
        else if(!root->left) return dfs(root->right, root->val, max);
        else if(!root->right) return dfs(root->left, min, root->val);
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);


    }
};
