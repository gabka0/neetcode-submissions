class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return helper(nums, 0);
        
    }
    vector<vector<int>> helper(vector<int>& nums, int i){
        if(i>=nums.size()) return {{}};
        vector<vector<int>> result;
        vector<vector<int>> prev = helper(nums, i+1);
        for(vector<int>& x: prev){
            for(int k=0; k<=x.size(); k++){
                vector<int> tmp = x;
                tmp.insert(tmp.begin()+k, nums[i]);
                result.push_back(tmp);
            }
        }
        return result;
    }
};
