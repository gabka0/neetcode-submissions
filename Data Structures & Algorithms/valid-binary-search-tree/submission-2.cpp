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
        int low = -INT_MAX;
        int high = INT_MAX;
        return dfs(root, low, high);
        
    }
    bool dfs(TreeNode* root, int low, int high){
        if(!root) return true;
        if(root->val<=low || root->val>=high) return false; 
        if(dfs(root->left, low, root->val) && dfs(root->right, root->val, high)){
            return true;
        }
        else return false;

    }
};
