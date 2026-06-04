class Solution {
private:
vector<vector<int>> memo;
public:
    int maxProfit(vector<int>& prices) {
        memo.assign(prices.size(), vector<int>(2, -1));
        return dfs(prices, 0, 1);
    }
    int dfs(vector<int>& prices, int i, int status){
        if(i>=prices.size()){
            return 0;
        }
        if(memo[i][status]!=-1){
            return memo[i][status];
        }
        if(status==1){
            memo[i][status] = max(dfs(prices, i+1, 1), -prices[i]+dfs(prices, i+1, 0));
        }
        else if(status==0){
            memo[i][status] = max(dfs(prices, i+1,0), prices[i]+dfs(prices, i+2, 1));
        }
        return memo[i][status];
        
    }
};
