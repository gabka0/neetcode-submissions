class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> subset;
        vector<int> curset;
        helper(candidates, target, 0, subset, curset, 0);
        return subset;
        
        
    }
    void helper(vector<int>& candidates, int target, int curSum,vector<vector<int>>& subset,
        vector<int>& curset, int i){
            if(curSum==target){
                subset.push_back(curset);
                return;
            }
            if(i>=candidates.size() || curSum>target){
                return;
            }
            for(int j=i; j<candidates.size();j++){
                if(j>i && candidates[j]==candidates[j-1]){
                    continue;
                }
            curset.push_back(candidates[j]);
            helper(candidates, target, curSum+candidates[j], subset, curset, j+1);
            curset.pop_back();
    

            }

        }

};
