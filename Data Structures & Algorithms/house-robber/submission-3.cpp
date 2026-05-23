class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size());
        return dfs(0, nums, cache);
        
    }

    int dfs(int i, vector<int>& nums, vector<int>& cache){
        if(i>=nums.size()){
            return 0;
        }
        if(cache[i]) return cache[i];
        int ans = max(nums[i]+dfs(i+2, nums, cache), dfs(i+1, nums, cache));
        cache[i] = ans;
        return ans;
    }
};
