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
int count = 0;
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int pathMax = root->val;
        dfs(root, pathMax);
        return count;
    }
    void dfs(TreeNode* root, int pathMax){
        if(root->val<pathMax);
        else {
            pathMax = root->val;
            count++;
        }
        if(root->left) dfs(root->left, pathMax);
        if(root->right) dfs(root->right, pathMax);

    }

};
