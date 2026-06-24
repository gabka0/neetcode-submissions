class Solution {
vector<vector<int>> memo;
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        memo.assign(nums.size(), vector<int>(target+1, -1));
        return dfs(nums, 0, 0, target); 
    }
    bool dfs(vector<int>& nums, int i, int curSum, int target){
        if(curSum==target) return true;
        if(i>=nums.size() || curSum>target) return false;
        if(memo[i][curSum]!=-1) return memo[i][curSum];
        memo[i][curSum] = dfs(nums, i+1, curSum, target) || dfs(nums, i+1, curSum+nums[i], target);
        return memo[i][curSum];

    }
};
