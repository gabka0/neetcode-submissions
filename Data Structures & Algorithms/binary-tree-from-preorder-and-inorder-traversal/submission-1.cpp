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
    unordered_map<int, int> inorder_map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* dfs(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int in_index = inorder_map[root->val];
        int left_size = in_index - in_start;
        
        root->left = dfs(preorder, pre_start + 1, pre_start + left_size, inorder, in_start, in_index - 1);
        root->right = dfs(preorder, pre_start + left_size + 1, pre_end, inorder, in_index + 1, in_end);
        
        return root;
    }
};

