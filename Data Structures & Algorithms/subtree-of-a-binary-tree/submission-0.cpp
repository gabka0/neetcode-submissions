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
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root || !subroot) return false;
        if(sameTree(root, subroot)|| isSubtree(root->left, subroot) || isSubtree(root->right, subroot) ) return true;
        return false;
        
    }
    bool sameTree(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(p && q && p->val==q->val) return sameTree(p->right, q->right) && sameTree(p->left, q->left);
        return false;
    }
};
