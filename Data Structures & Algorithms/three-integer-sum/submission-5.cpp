class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]+nums[i]==0){
                    ans.push_back({nums[left], nums[right], nums[i]});
                    left++;
                    right--;
                    while(left<right && nums[left-1]==nums[left]){
                        left++;
                    }
                    while(left<right && nums[right+1]==nums[right]){
                        right--;
                    }
                }
                else if(nums[left]+nums[right]+nums[i]<0){
                    left++;
                }
                else{
                    right--;
                }
            } 
        }
        return ans;
        
    }
};
