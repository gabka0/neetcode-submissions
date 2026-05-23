class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0;
        int sum = 0;
        int length = 1000000;
        for(int R=0; R<nums.size();R++){
            sum += nums[R];
            while(sum>=target){
                length = min(R-L+1, length);
                sum -= nums[L];
                L++;
            }
        }
        return length==1000000 ? 0 : length;
        
    }
};