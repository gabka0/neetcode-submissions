class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo (nums.size(), vector<int>(nums.size() + 1, -1));
        return dfs(nums, 0, -1, memo);
    }

private:
    int dfs(vector<int>& nums, int i, int j, vector<vector<int>>& memo) {
        if (i == nums.size()) {
            return 0;
        }
        if (memo[i][j + 1] != -1) {
            return memo[i][j + 1];
        }


        int LIS = dfs(nums, i + 1, j, memo); // not include

        if (j == -1 || nums[j] < nums[i]) {
            LIS = max(LIS, 1 + dfs(nums, i + 1, i, memo)); // include
        }
        memo[i][j+1] = LIS;

        return LIS;
    }
};