class Solution {
vector<int> memo;
public:
    int climbStairs(int n) {
        memo.assign(n+1, -1);
        return dp(n);
        
    }
    int dp(int n){
        if(n==1) return 1;
        if(n==0) return 1;
        if(memo[n]!=-1) return memo[n];
        memo[n]=dp(n-1)+dp(n-2);
        return memo[n];
    }
};
