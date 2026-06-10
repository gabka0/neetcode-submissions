class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> ans (nums.size(),0);
        int zero_count = 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]!=0) product *= nums[i];
            else zero_count++;
        }
        if(zero_count>1) return ans;
        for(int i=0; i<nums.size();i++){
            if(zero_count==1 && nums[i]==0){ 
                ans[i] = product;
            }
            else if(zero_count==1 && nums[i]!=0) ans[i] = 0;
            else ans[i] = product/nums[i];
        }
        return ans;


    }
};
