class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo (amount+1, -1);
        int ans = dfs(coins, amount, memo);
        if(ans>=1e9) return -1;
        return ans;
    
    }
    int dfs(vector<int>& coins, int amount, vector<int>& memo){
        if(amount==0){
            return 0;
        }
        if (memo[amount] != -1) return memo[amount];
        int ans = 1e9;
        for(int coin: coins){
            if(amount-coin>=0){
            ans = min(ans, 1+dfs(coins, amount-coin, memo));
            }    
        }
        memo[amount] = ans;
        return ans;

    }
};
