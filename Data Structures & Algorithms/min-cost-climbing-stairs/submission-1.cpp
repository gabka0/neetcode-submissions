class Solution {
vector<int> memo;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memo.assign(cost.size(), -1);
        return min(dfs(cost,1), dfs(cost,0));
        
    }
    int dfs(vector<int>& cost, int i){
        if(i>=cost.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        memo[i] = cost[i]+min(dfs(cost, i+1), dfs(cost,i+2));
        return memo[i];


    }
};
