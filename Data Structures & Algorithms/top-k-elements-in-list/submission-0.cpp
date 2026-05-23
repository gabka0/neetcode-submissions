class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        for(int i = 0; i < nums.size(); i++){
            umap[nums[i]]++;
        }

        vector<pair<int, int>> arr;

        for (const auto& p : umap) {
            arr.push_back({p.second, p.first});
        }

        sort(arr.begin(), arr.end());

        vector<int> res;

        for (int i = (int)arr.size() - 1; i >= (int)arr.size() - k; i--) {
            res.push_back(arr[i].second);
        }

        return res;
    }
};