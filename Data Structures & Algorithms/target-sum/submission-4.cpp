class Solution {
vector<vector<int>> memo;
int offset;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0; i<nums.size();i++){
            sum+=nums[i];
        }
        offset = sum;
        memo.assign(nums.size(), vector<int>(2*sum+1, -1));
        return dfs(0, nums, 0, target);
        
    }
    int dfs(int i, vector<int>& nums, int cursum, int target){
        int idx = cursum + offset;
        if(i>=nums.size() && target==0) return 1;
        if(i>=nums.size()&& target!=0) return 0;
        if(memo[i][idx]!=-1) return memo[i][idx];
        memo[i][idx] = dfs(i+1, nums, cursum-nums[i], target+nums[i])+dfs(i+1, nums,cursum+nums[i], target-nums[i]);
        return memo[i][idx];
    
    }

};
