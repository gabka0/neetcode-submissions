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
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::queue;
using std::vector;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode*> queue;
        int level = 0;
        vector<vector<int>> ans;
        if(root){
            ans.push_back(vector<int>{root->val});;
            queue.push(root);
        }
        while(queue.size()>0){
            int length = queue.size();
            vector<int> ans1;
            for(int i=0; i<length; i++){
                TreeNode* curr = queue.front();
                queue.pop();
                if(curr->left){
                    ans1.push_back(curr->left->val);
                    queue.push(curr->left);
                }
                if(curr->right){
                    ans1.push_back(curr->right->val);
                    queue.push(curr->right);
                }
            }
            if(queue.size()>0){
            ans.push_back(ans1);
            }

        }
        return ans;
        
        
    }
};
