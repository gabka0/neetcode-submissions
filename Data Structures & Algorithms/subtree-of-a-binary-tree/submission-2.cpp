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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if(dfs(root, subRoot)) return true;
        if(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)) return true;
        return false;
        }
        
    bool dfs(TreeNode* r, TreeNode* q){
        if(!r && !q) return true;
        if(r && !q) return false;
        if(!r && q) return false;
        if(r->val!=q->val) return false;
        if(dfs(r->left, q->left) && dfs(r->right, q->right)){
            return true;
        }
        return false;
    }
};
