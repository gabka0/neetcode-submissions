class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size());
        return min(dfs(0,cost,cache), dfs(1,cost,cache));
        
    }
    int dfs(int pos, vector<int>& cost, vector<int>& cache){
        if(pos>=cost.size()){
            return 0;
        }
        if(cache[pos]) return cache[pos];
        int res = cost[pos] + min(dfs(pos+1, cost, cache), dfs(pos+2, cost, cache));
        cache[pos] = res;
        return res;  
    }
};
