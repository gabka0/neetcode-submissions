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
private:
int goodPaths = 0;
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, root->val);
        
    }
    int dfs(TreeNode* root, int pathMax){
        if(root->val >= pathMax){
            goodPaths++;
        }
        pathMax = max(root->val, pathMax);
        if(root->left) dfs(root->left, pathMax);
        if(root->right) dfs(root->right, pathMax);
        return goodPaths;
    }
};
