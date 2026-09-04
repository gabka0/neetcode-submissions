class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curset;
        helper(0, curset, ans, nums);
        return ans;
    }
    void helper(int i, vector<int>& curset, vector<vector<int>>& ans, vector<int>& nums){
        if(i>=nums.size()){
            ans.push_back(curset);
            return;
        }
        helper(i+1, curset, ans, nums);
        curset.push_back(nums[i]);
        helper(i+1, curset, ans, nums);
        curset.pop_back();

    }
};
