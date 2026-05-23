class Solution {
unordered_map<int, int> answer;
public:
    int rob(vector<int>& nums) {
        return dfs(0, nums);
        
    }
    int dfs(int i, vector<int>& nums){
        if(i>=nums.size()){
            return 0;
        }
if (answer.find(i) != answer.end()) {
            return answer[i];
        }
        else{
            answer[i]=max(nums[i]+dfs(i+2, nums), dfs(i+1,nums));
        }
        return answer[i];
    }
};
