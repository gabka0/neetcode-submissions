class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> subset;
        vector<int> curset;
        int cur = 0;
        int curSum = 0;
        helper(cur, curSum, target, subset, curset, nums);
        return subset;

        
    }
    void helper(int cur, int curSum, int target, vector<vector<int>>& subset, vector<int>& curset, vector<int>& nums){
        if(curSum==target){
            subset.push_back(curset);
            return;
        }
        if(curSum>target || cur>=nums.size()) return;
        curset.push_back(nums[cur]);
        helper(cur, curSum+nums[cur], target, subset, curset, nums);
        curset.pop_back();
        helper(cur+1, curSum, target, subset, curset, nums);


    }
};
