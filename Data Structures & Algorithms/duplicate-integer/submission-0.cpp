class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for(int i=0; i<nums.size();i++){
            if(countMap.count(nums[i])==0){
                countMap[nums[i]]=0;
            }
            else{
                return true;
            }
        }
        return false;

    }
};
               