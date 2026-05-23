class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curset;
        vector<vector<int>> subset;
        helper(0, nums, curset, subset);
        return subset;
        
    }
    void helper(int num, vector<int>& nums, vector<int>& curset, vector<vector<int>>& subset){
        if(num>=nums.size()){
            subset.push_back(curset);
            return;
        }
        curset.push_back(nums[num]);
        helper(num+1, nums, curset, subset);
        curset.pop_back();
        while(num+1<=nums.size() && nums[num]==nums[num+1]){
            num++;
        }
        helper(num+1, nums, curset, subset);


    }
};
