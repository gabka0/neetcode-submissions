class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;

        for(int i = 0; i < nums.size(); i++) {

            int target = -nums[i];
            unordered_set<int> seen;

            for(int j = i + 1; j < nums.size(); j++) {

                int diff = target - nums[j];

                if(seen.count(diff)) {
                    vector<int> trip = {nums[i], diff, nums[j]};
                    sort(trip.begin(), trip.end());
                    res.insert(trip);
                }

                seen.insert(nums[j]);
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};