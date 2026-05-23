class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curset;
        helper(0, subsets, curset, nums);
        return subsets;

        
    }
    void helper(int num, vector<vector<int>>& subsets, vector<int>& curset, vector<int>& nums){
        if(num>=nums.size()) {
            subsets.push_back(curset);
            return;
        }
        curset.push_back(nums[num]);
        num++;
        helper(num, subsets, curset, nums);
        curset.pop_back();
        helper(num, subsets, curset,nums);
        
    }
};
