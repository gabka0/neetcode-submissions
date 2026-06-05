class Solution {
private:
vector<vector<int>> memo;
public:
    int change(int amount, vector<int>& coins) {
        memo.assign(amount+1, vector<int>(coins.size(), -1));
        return dfs(amount, coins, 0);
    }
    int dfs(int amount, vector<int>& coins, int i){
        if(amount==0){
            return 1;
        }
        if(amount<0) return 0;
        if(memo[amount][i]!=-1){
            return memo[amount][i];
        }
        int ans = 0;
        for(int j=i; j<coins.size();j++){
             ans+=dfs(amount-coins[j], coins, j);
        }
        memo[amount][i] = ans;
        return ans;
    }
};
