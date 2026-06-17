class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curSet;
        vector<vector<int>> ans;
        helper(nums, curSet, ans, 0);
        return ans;     
    }
    void helper(vector<int>& nums, vector<int>& curSet, vector<vector<int>>& ans, int i){
        if(i>=nums.size()) {
            ans.push_back(curSet);
            return;
            }
        helper(nums, curSet, ans, i+1);
        curSet.push_back(nums[i]);
        helper(nums, curSet, ans, i+1);
        curSet.pop_back();
    }
};
