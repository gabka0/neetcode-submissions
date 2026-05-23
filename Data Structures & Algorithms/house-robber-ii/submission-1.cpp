class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> cache1(nums.size()-1,-1);
        vector<int> cache2(nums.size()-1, -1);
        vector<int> nums1 (nums.begin(), nums.end()-1);
        vector<int> nums2 (nums.begin()+1, nums.end());
        return max(dfs(0, nums1, cache1), dfs(0, nums2, cache2));
        
    }

    int dfs(int i, vector<int>& nums, vector<int>& cache){
        if(i>=nums.size()){
            return 0;
        }
        if(cache[i]!=-1) return cache[i];
        int ans = max(nums[i]+dfs(i+2, nums, cache), dfs(i+1, nums, cache));
        cache[i] = ans;
        return ans;
    }
};
