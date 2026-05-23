class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int dp[2];
        dp[0]=1;
        dp[1]= 2;
        int i=2;
        while(i<n){
            int temp = dp[1];
            dp[1] = dp[0] +dp[1];
            dp[0] = temp;
            i+=1;
        }
        return dp[1];
        
    }
};
