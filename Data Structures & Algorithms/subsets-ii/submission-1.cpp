class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curset;
        vector<vector<int>> ans;
        helper(nums, ans, curset,0);
        return ans;
    }
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curset, int i){
        if(i>=nums.size()) {
            ans.push_back(curset);
            return;
        }
        curset.push_back(nums[i]);
        helper(nums, ans, curset, i+1);
        curset.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        helper(nums, ans, curset, i+1);

    }
};
