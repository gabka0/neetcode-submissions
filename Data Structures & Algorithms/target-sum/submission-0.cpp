class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, nums, target);
        
    }
    int dfs(int i, vector<int>& nums, int target){
        if(i>=nums.size() && target==0) return 1;
        if(i>=nums.size()&& target!=0) return 0;
        return dfs(i+1, nums, target+nums[i])+dfs(i+1, nums, target-nums[i]);
        

    }

};
