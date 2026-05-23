class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curset;
        vector<vector<int>> subset;
        int count = 0;
        helper(n, k, count, curset, subset);
        return subset;
    }
    void helper(int n,int k,int count, vector<int>& curset, vector<vector<int>>& subset){
        if(count>n || curset.size()>k) {
            return;
        }
        if(curset.size()==k){
            subset.push_back(curset);
            return;
        }
        curset.push_back(count+1);
        helper(n, k, count+1, curset, subset);
        curset.pop_back();
        helper(n, k, count+1, curset, subset);

    }
};