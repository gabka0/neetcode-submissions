class Solution {
private:
vector<vector<int>> memo; 
public:
    int maxProfit(vector<int>& prices) {
        memo.assign(prices.size(), vector<int>(2, -1));
        return dfs(prices, 0, 0); 
    }
    int dfs(vector<int>& prices, int state, int day){
        if(day>=prices.size()) return 0;
        if(memo[day][state]!=-1) return memo[day][state];
        if(state==0){
            memo[day][state] = max(-prices[day]+dfs(prices, 1, day+1), dfs(prices, 0, day+1));
        }
        if(state==1){
            memo[day][state] = max(prices[day]+dfs(prices, 0, day+2), dfs(prices, 1, day+1));
        }
        return memo[day][state];

    }
};
