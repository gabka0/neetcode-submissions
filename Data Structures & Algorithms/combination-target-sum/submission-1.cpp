class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curset;
        vector<vector<int>> ans;
        helper(curset, ans, nums, 0, target, 0);
        return ans;
        
    }
    void helper(vector<int>& curset, vector<vector<int>>& ans, vector<int>& nums, int i, int target, int cursum){
        if(cursum==target) {
            ans.push_back(curset);
            return;
        }
        if(cursum>target || i>=nums.size()) return;
        curset.push_back(nums[i]);
        helper(curset, ans, nums, i,target, cursum+nums[i]);
        curset.pop_back();
        helper(curset, ans, nums, i+1, target, cursum);
        
    }
};
