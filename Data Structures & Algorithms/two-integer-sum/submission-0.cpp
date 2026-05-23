class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> checkMap;
        vector <int> ans;
        for(int i=0; i<nums.size(); i++){
            int difference = target - nums[i];
            if(checkMap.count(difference)==0){
                checkMap[nums[i]] = i;
            }
            else{
                ans.push_back(checkMap[difference]);
                ans.push_back(i);
                break;
            }

        }
        return ans;
    }
};
