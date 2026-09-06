class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<bool> curState(nums.size(), false);
        vector<int> curSet;
        helper(nums, curState, curSet, ans);
        return ans;

    }
    void helper(vector<int>& nums, vector<bool>& curState, vector<int>& curSet, vector<vector<int>>& ans){
        if(curSet.size()==nums.size()){
            ans.push_back(curSet);
            return;
        }
        for(int i=0; i<nums.size();i++){
            if(curState[i]==true) continue;
            curSet.push_back(nums[i]);
            curState[i] = true;
            helper(nums, curState, curSet, ans);
            curSet.pop_back();
            curState[i] = false;

        }


    }
};
